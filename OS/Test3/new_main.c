#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>


int find_commands_cnt(int fd)
{
   int bytes = lseek(fd,0,SEEK_END);
   if(bytes == -1)
        return -1;
   if(lseek(fd,0,SEEK_SET) == -1) 
        return -1;            
    int cnt = 0;
    char symbol;
    for(int i = 0;i < bytes;i++)
    {
         if(read(fd,&symbol,1) == -1)
               return -1;

         if(symbol == '\n')
            cnt++;  

    }

    return cnt;
}

int get_cnt(char* atributes)
{
    int cnt = 0;
    for(int i = 0;i < strlen(atributes);i++)
    {

         if(atributes[i] == ' ')
            cnt++;  
    }
    cnt++;
    return cnt;

}


char* get_line(int fd)
{
    char *buff = malloc(sizeof(char)*20);
    char symbol;
    int i = 0;
    while(read(fd,&symbol,sizeof(char)))
    {
         if(symbol == '\n')
            break;
         else
         {
            buff[i] = symbol; 
            i++;
         }
    }
    return buff;
}

char* get_command(char* buff)
{
    char *command = malloc(sizeof(char*)*20);
    for(int i = 0;i < strlen(buff);i++)
    {
        
         if(buff[i] == ' ')
            break;
         else
            command[i] = buff[i];  
    }

    return command;
}

char* get_word(char* buff,int which_word)
{
    char *word = malloc(sizeof(char)*20);
    int j = 1, i = 0;
    for(;j < which_word;i++)
    {
        if(buff[i] == ' ')
            j++;
    }

    for(int k = 0;buff[i] != ' ' && buff[i] != '\n';k++)
    {
        word[k]=buff[i];
        i++;
    }

    return word;
}




int main(int argc, char* argv[])
{
   int fd = open(argv[1],O_RDONLY);
   if(fd == -1) err(1,"File cannot open!");


   int commands_cnt = find_commands_cnt(fd);
   if(commands_cnt == -1)
   {
        close(fd);
        err(1,"Commands count failed!"); 
   }
    if(lseek(fd,0,SEEK_SET) == -1) 
       {
            close(fd);
            err(1,"Lseek failed!"); 
        }  
    
    for(int index = 0; index < commands_cnt - 1; index++)
    {
        pid_t id = fork();
        if(id == -1)
        {
            close(fd);
            err(1,"Fork doesnt work!");
        }

        if(id == 0)
        {   
            char* line = get_line(fd);

            int atributes_cnt = get_cnt(line);


            char* atrib[atributes_cnt+1];
            int j = 0;
            for(;j < atributes_cnt;j++)
            {
                  if(j == 0)
                    atrib[j] = get_command(line);
                  else
                    atrib[j] = get_word(line,j);
            }
            atrib[++j] = NULL;
            
           
			
            if(execvp(atrib[0],atrib) < 0)
            {
                close(fd);
                err(1,"Execvp() failed!");
            }
        }
        else
        {
            int status;
			wait(&status);
			
			
			printf("Exit status is: %d\n", WEXITSTATUS(status));

        }
    }
    
    return 0;
}
