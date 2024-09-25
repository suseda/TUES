#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>




int strlength(const char *str)
{
	int i=0;
	while(*str != '\0')
	{
		*str++;
		i++;
	}
	return i;
}


char* str_cat(const char* one, const char* two)
{
	int size = strlength(one) + strlength(two);
	char* new_arr = malloc(size);
	if(!new_arr)  exit(1);
	int i,j;
	for(i=0;i<strlength(one);++i)
	{
		new_arr[i]=one[i];
	}
	
	for(j=0;j<strlength(two);++j,++i)
	{
		new_arr[i]=two[j];
	}
	
	new_arr[i]='\0';
	return new_arr;
}


void swap_int(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}



void swap(void *c,void *d, int size)
{
   char tmp,*a=c,*b=d;
   for(int i=0;i<size;i++)
   {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
   }
}


char* str_dup(const char* string)
{
    char* new_str = malloc(sizeof(string));
    if(!new_str)  exit(2);
    for(int i=0;i<strlength(string);i++)
    {
        new_str[i]=string[i];
    }
    return new_str;
}


char* readline(int fd)
{
    /*char symbol;
    char *buffer;
    int i=0;
    while(read(fd,&symbol,1) == 1 && symbol != '\n')
    {
        buffer[i]=symbol;
        i++;
    }

    return buffer;*/
    
    char symbol;
    int i = 0;
    for(;read(fd,&symbol,1) == 1 && symbol != '\n';i++);
    lseek(fd,0,SEEK_SET);
    char* buffer = malloc(i);
    read(fd,buffer,i);
    return buffer;
}



int main()
{
    printf("String length\n");
	int res = strlength("abcd");
	printf("%d\n",res);
	
	printf("String cat:\n");
	char* buff = str_cat("Hello ","World!");
	printf("%s\n",buff);


    printf("Swap Integers:\n");
    int a = 2,b = 3;
    swap_int(&a,&b);
    printf("%d %d\n",a,b);

    
	printf("Swap:\n");
    //double c = 2.2,d = 3.3;
    char c = 's',d = 'k';
    swap(&c,&d,sizeof(c));
    printf("%c %c\n",c,d);

    
    printf("Str_dup:\n");
    char* buf = str_dup("Hello");
	printf("%s\n",buf);


    printf("Read line:\n");
    int fd = open("text.txt",O_RDONLY);
    if(fd == -1)
        exit(3);
    char *buffer = readline(fd);
    printf("%s\n", buffer);
    close(fd);

    return 0;
}
