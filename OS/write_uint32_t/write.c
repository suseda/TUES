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
	uint32_t arr[2] = {1,2};
	int fd = open("f.txt",O_WRONLY);
	if(fd == -1) 
    {
        close(fd);
        err(1,"File cannot open!");
    }
    
    for(uint32_t i = 0; i < 2; i++)
    {
    	write(fd,&arr[i],sizeof(uint32_t));
    }

	close(fd);
    
    return 0;
	
}
