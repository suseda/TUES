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
	int fd1_dat = open(argv[0],O_RDONLY);
    int fd1_idx = open(argv[1],O_RDONLY);
    int fd2_dat = open(argv[2],O_RDWR | O_TRUNC | O_CREAT);
    int fd2_idx = open(argv[3],O_RDWR | O_TRUNC | O_CREAT);
    
    uint16_t base;
    uint8_t length;
    char *buf;

        
    /*uint8_t *buf_8 = malloc(sizeof(uint8_t));
    if(!buf_8) err(1,"Cannot allocate memory!");
    uint16_t *buf_16 = malloc(sizeof(uint16_t));
    if(!buf_16) err(1,"Cannot allocate memory!");*/

    while(read(fd1_idx,&base,sizeof(uint16_t)))
    {

        if(!read(fd1_idx,&length,sizeof(uint8_t)))
        {
            err(1,"Cannot read!");
            close(fd1_dat);
            close(fd1_idx);
            close(fd2_dat);
            close(fd2_idx);
        }
        
        lseek(fd1_idx,length,SEEK_CUR);
        buf = malloc(sizeof(length));
        if(!buf) err(1,"Cannot allocate memory!");
        
        lseek(fd1_dat,base,SEEK_CUR);
        if(!read(fd1_dat,buf,sizeof(uint8_t)))
        {
            err(1,"Cannot read!");
            close(fd1_dat);
            close(fd1_idx);
            close(fd2_dat);
            close(fd2_idx);
        }

        if(buf[0] >= 'A' && buf[0] <= 'Z')
        {
            write(fd2_idx,&base,sizeof(uint16_t));
            write(fd2_idx,&length,sizeof(uint8_t));
            write(fd2_dat,buf,sizeof(uint8_t));
        } 
        free(buf);
    }


    close(fd1_dat);
    close(fd1_idx);
    close(fd2_dat);
    close(fd2_idx);

    return 0;
	
}
