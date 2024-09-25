#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int fd = open("file1.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Cannot open file");
        exit(0);
    }


    char buff[1];
    int r;
    while( 1 == (r = read(fd, &buff, 1) ) )
    {
        
        
        if(-1 == write(1,&buff,1))
        {
            printf("Problem with write!");
            close(fd);
            exit(1);        
        }

    }


    close(fd);
    return 0;
}
