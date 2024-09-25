#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>

int main(int argc, char * argv[])
{
    
    uint32_t arr[4] = {1, 7, 2, 5};
        
	int fd1 = open("f1.bin",O_RDWR | O_TRUNC);
	if(fd1 == -1) 
    {
        close(fd1);
        err(1,"File cannot open!");
    }
    int fd2 = open("f2.bin",O_RDWR | O_TRUNC);
	if(fd2 == -1) 
    {
        close(fd2);
        err(1,"File cannot open!");
    }
    int fd3 = open("f3",O_WRONLY | O_TRUNC);
	if(fd3 == -1) 
    {
        close(fd3);
        err(1,"File cannot open!");
    }

    for(uint32_t i = 0; i < 4; i++)
    {
        write(fd1,&arr[i],sizeof(uint32_t));
    }

    for(uint32_t i = 0; i < 10; i++)
    {
        write(fd2,&i,sizeof(uint32_t));
    }
    
    uint32_t size = lseek(fd1,0,SEEK_END);
    lseek(fd1,0,SEEK_SET);
    lseek(fd2,0,SEEK_SET);
    
    uint32_t *buf = malloc(sizeof(uint32_t));
    /*if(buf == NULL)
    {
        close(fd1);
        close(fd2);
        close(fd3);
        err(1,"Cannot allocate memory!");
    }*/
   
    while(size)
    {
        read(fd1,buf,sizeof(uint32_t));
        size = size - sizeof(uint32_t);
        uint32_t index = *buf;

        lseek(fd2,index * sizeof(uint32_t),SEEK_SET);
        printf("Start index: %" PRIu32 "\n",*buf);
        
        read(fd1,buf,sizeof(uint32_t));
        size = size - sizeof(uint32_t);
        uint32_t move = *buf;
        printf("Move: %" PRIu32 "\n",move);

        
        for(uint32_t i = 0; i < move; i++)
        {
            read(fd2,buf,sizeof(uint32_t));
            //printf("%" PRIu32 "\n",buf);
            write(fd3,buf,sizeof(uint32_t));   
        }   
        
        //lseek(fd2,0,SEEK_SET);  
    }
    
    free(buf);
     
    close(fd1);
    close(fd2);
    close(fd3);

	return 0;
}
