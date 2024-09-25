#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>



void print_lines(int fd,int number)
{
	/*char symbol;
	int lines = 0;
	while(read(fd,&symbol,1) == 1 && number > 0)
	{
		if(symbol == '\n')
			number--;	
		
		printf("%c",symbol);
		            
	}*/
    char chunk[16];
    while(read(fd,&chunk,16))
    {
        for(int i = 0;chunk[i]!='\0' && number > 0; i++)
        {
                if(chunk[i] == '\n')
                    number--;
                printf("%c",chunk[i]);
        }  
    }
}


int is_number(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] < '0' || s[i] > '9')
            return 0;
 
    return 1;
}



int main(int argc, char ** argv)
{
    if(argc < 2) err(1,"Not enough arguments!");
    int fd = open (argv[1],O_RDONLY);
    if(fd == -1) err(1,"File cannot open!");
    
    if(argc == 2)
    { 
		print_lines(fd,10);
    } 
    else
    {
        if(strcmp(argv[2],"-n"))
            err(1,"Third argument must be -n!");
        
        if(!is_number(argv[3]))
            err(1,"Fourth argument must be number");      
        
        int number = atoi(argv[3]);
		print_lines(fd,number); 
	}
    
    close(fd);
	return 0;
}

