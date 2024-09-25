#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


void start_print(int fd)
{
	char symbol;
	while(read(fd,&symbol,1) == 1)
	{	
		printf("%c",symbol);	            
	}
}


void print_lines(int fd,int file_lines,int given_lines)
{
	int lines_to_start_print = file_lines - given_lines;
	if(lines_to_start_print <= 0)
	{
		start_print(fd);
    }
    else
    {
		int temp_for_lines = 0;
		
		char symbol;
		while(read(fd,&symbol,1) == 1)
		{
			if(symbol == '\n')
				temp_for_lines++;
			if(temp_for_lines == lines_to_start_print)
				break;	            
		}
		
		start_print(fd);
        
	}
}


int is_number(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] < '0' || s[i] > '9')
            return 0;
 
    return 1;
}


int lines_count(int fd)
{
	char symbol;
	int lines=0;
	while(read(fd,&symbol,1) == 1)
	{
		if(symbol == '\n')
			lines++;	        
	}
	return lines;
}



int main(int argc, char ** argv)
{
	if(argc < 2) err(1,"Not enough arguments");
    int fd = open (argv[1],O_RDONLY);
    if(fd == -1) err(1,"File cannot open!");
    
    int lines = lines_count(fd);
    
    if(lseek(fd,0,SEEK_SET) == -1) err(1,"Lseek doesnt work!");
    
    if(argc == 2)
    { 
    	if(lines < 10)
			print_lines(fd,lines,lines);
		else
			print_lines(fd,lines,10);
    } 
    else
    {
        if(strcmp(argv[2],"-n"))
            err(1,"Third argument must be -n!");
        
        if(!is_number(argv[3]))
            err(1,"Fourth argument must be number!");     
        
        int number = atoi(argv[3]);
		print_lines(fd,lines,number); 
	}
    
    close(fd);
	return 0;
}
