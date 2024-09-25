#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int fd1 = open("a.txt",O_RDONLY);
    if(fd1 == -1)
    {
        printf("Cannot open file");
        exit(0);
    }

    int fd2 = open("b.txt",O_WRONLY | O_TRUNC);
    if(fd2 == -1)
    {
        printf("Cannot open file");
        exit(1);
    }

    char buff[1];
    int r;
    while( 1 == (r = read(fd1, &buff, 1) ) )
    {   
	     if(-1 == write(fd2,&buff,1))
            {
                printf("Problem with write");
			    close(fd2);
			    exit(2);
            }
    }

    close(fd2);
    close(fd1);

    return 0;
}
