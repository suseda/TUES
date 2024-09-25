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
    
    int fd2 = open(argv[2],O_RDONLY);
	if(fd2 == -1) 
    {
        close(fd1);
        err(1,"File2 cannot open!");
    }
    
    int patch = open(argv[3],O_WRONLY | O_TRUNC);
	if(patch == -1) 
    {
        close(fd1);
        close(fd2);
        err(1,"File3 cannot open!");
    }
    
    uint16_t offset = 0;
    uint8_t new,old;    

    while(read(fd1,&old,sizeof(uint8_t)) && read(fd2,&new,sizeof(uint8_t)))
    {
        
        if(old == new)
            offset++;
        else
        {
            write(patch,&offset,sizeof(uint16_t));
            write(patch,&old,sizeof(uint8_t));
            write(patch,&new,sizeof(uint8_t));
            offset++;
        }

    }

    close(fd1);
    close(fd2);
    close(patch);

    return 0;
}
