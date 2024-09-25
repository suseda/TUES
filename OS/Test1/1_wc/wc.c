#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


int main(int argc, char** argv)
{
    if(argc < 2) err(1,"Not enough arguments!");
    int fd = open(argv[1],O_RDONLY);
    if(fd == -1) err(1,"File cannot open!");
    int  lines = 0;
    int bytes = lseek(fd,0,SEEK_END);
    if(bytes == -1) err(1,"Cannot find bytes of the file!");
    if(lseek(fd,0,SEEK_SET) == -1) err(1,"Lseek doesnt work!");
    /*char symbol;
    while(read(fd,&symbol,1) == 1)
    {
            if(symbol == '\n')
                lines++;
    }*/

    char chunk[16];
    while(read(fd,&chunk,16))
    {
        for(int i = 0;chunk[i]!='\0'; i++)
        {
                if(chunk[i] == '\n')
                    lines++;
        }  
    }

    
  
    
    


    if(argc == 2)
    {
         printf("Lines: %d Bytes:%d\n",lines,bytes);
    }
    else
    {
        if(argc == 3)
        {
            if(!(strcmp("-l",argv[2])))
                printf("Lines: %d\n",lines);
            else
               {
                     if(!(strcmp("-c",argv[2])))
                         printf("Bytes: %d\n",bytes); 
                     else
                        err(1,"Wrong input!");
               }
 
        }
        else
        {
            int u1 = !(strcmp("-l",argv[2])) && !(strcmp("-c",argv[3]));
            int u2 = !(strcmp("-l",argv[3])) && !(strcmp("-c",argv[2]));
            if(u1 || u2 )
                printf("Lines: %d Bytes:%d\n",lines,bytes);
            else
                err(1,"Wrong input!");
        }
    }
    close(fd);
    return 0;
}
