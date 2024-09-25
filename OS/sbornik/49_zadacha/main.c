#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>



int main(int argc, char* argv[])
{
    
    int fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1) 
    {
        err(1,"File1 cannot open!");
    }
    
    int patch = open(argv[2],O_RDONLY);
	if(patch == -1) 
    {
        close(fd1);
        err(1,"File2 cannot open!");
    }
    
    int fd2 = open(argv[3],O_WRONLY | O_TRUNC);
	if(fd2 == -1) 
    {
        close(fd1);
        close(patch);
        err(1,"File3 cannot open!");
    }
    
    uint16_t offset = 0;
    uint8_t new,old;

    for(uint16_t i = 0;read(fd1,&old,sizeof(uint8_t));i++)
    {
        if(i == offset)
        {
            read(patch,&offset,sizeof(uint16_t));
            read(patch,&old,sizeof(uint8_t));
            read(patch,&new,sizeof(uint8_t));
            write(fd2,&new,sizeof(uint8_t));
        }
        else
        {
            write(fd2,&old,sizeof(uint8_t));
        }
        

    }

    close(fd1);
    close(fd2);
    close(patch);


    return 0;
}
