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
    int cnt = 0;
    char symbol;
    for(;0 < bytes;bytes--)
    {
         if(read(fd,&symbol,sizeof(char)) == -1)
               return -1;
         if(symbol == "\n")
            cnt++;  

    }

    return cnt;
}

int get_atributes_cnt(char* atributes)
{
    int cnt = 0;
    int size = sizeof(atributes)/sizeof(atributes[0]);
    for(int i = 0;i < size;i++)
    {
       
         if(atributes[i] == " " || atributes[i] == "\n")
            cnt++;  
    }
    return cnt;

}


char* get_command(char* buff)
{
    int size = sizeof(buff)/sizeof(buff[0]);
    char *command;
    for(int i = 0;i < size;i++)
    {
       
         if(buff[i] == " " || buff[i] == "\n")
            break;
         else
            command[i] = buff[i];  
    }

    return command;
}


char* get_line(int fd)
{
    char *buff;
    char symbol;
    int i = 0;
    while(1)
    {
         if(read(fd,&symbol,sizeof(char)) == -1)
          {
                close(fd);
                err(1,"Read doesnt work!");
          }
       
         if(symbol == "\n")
            break;
         else
         {
            buff[i] = symbol;  
            i++;
         }
    }
    return buff;
}


char* get_atributes(char* buff)
{
    int size = sizeof(buff)/sizeof(buff[0]);
    char* atributes;
    int flag = 1;
    for(int i = 0; i < size;i++)
    {
        if(flag && buff[i] != " " && buff[i]!= "\n")
            continue;
        else
        {
            flag = 0;
            i++;
            atributes[i] = buff[i];
        }
       
    }    
    return atributes;  
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
        err(1,"Lseek doesnt work!");
   }

   
    for(; 0 < commands_cnt; commands_cnt--)
    {
        pid_t id = fork();
        if(id == -1)
        {
            close(fd);
            err(1,"Fork doesnt work!");
        }
        printf("Id: %d\n",id);

        if(id == 0)
        {
            printf("In child");
            char* line = get_line(fd);
            char* command = get_command(line);
            char* atributes = get_atributes(line);
            int atributes_cnt = get_atributes_cnt(atributes);
            char* atrib[atributes_cnt+1];
            int j = 0;
            char* atribute;
            for(int i = 0;j < atributes_cnt; i++)
            {
                 if(atributes[i] == " " || atributes[i] == "\n")
                 {
                    atrib[j] = atribute;
                    j++;
                    memset(atribute,"\0",sizeof(atribute));
                 }

            }
            atrib[++j] = NULL;
           
             if(execvp(command,atributes) < 0)
                err(1,"Execvp() failed!");
        }
        else
        {
            int status;
            wait(&status);
           
            printf("Exit status: %d\n", WEXITSTATUS(status));
        }
    }
   
    return 0;
}
