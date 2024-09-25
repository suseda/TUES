
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


char* take_line(int fd, int which_line)
{
	if(lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		exit(4);
	}
	
	int lines_index = 1;
	int index = 0;
	int len = 0;
	char onindex;
	while(lines_index <= which_line)
	{
		if(read(fd, &onindex, 1) == -1)
		{
			close(fd);
			exit(5);
		}
		if(onindex == '\n')
		{
			
			if(lines_index + 1 == which_line)
			{
				len = index + 1;
				index = 0;
			}
			else
			{
				index++;
			}
			lines_index++;
		}
		else
		{
			index++;
		}
		
	}
	
	char* buffer = malloc(sizeof(char)* (index + 1));
	if(buffer == NULL)
	{
		close(fd);
		exit(6);
	}
	if(lseek(fd, len, SEEK_SET) == -1)
	{
		free(buffer);
		close(fd);
		printf("Lseek\n");
		exit(7);
	}
	
	if(read(fd, buffer, sizeof(char) * index) == -1)
	{
		free(buffer);
		close(fd);
		printf("Read\n");
		exit(8);
	}
	buffer[strlen(buffer) - 1] = '\0';
	return buffer;
}

int lines_count(int fd)
{
	int len = lseek(fd, 0, SEEK_END);
	if(len == -1)
	{
		close(fd);
		exit(9);
	}
	if(lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		exit(10);
	}

	int index = 0;
	int line_count = 0;
	char onindex;
	while(index < len)
	{
		if(read(fd, &onindex, 1) == -1)
		{
			close(fd);
			exit(11);
		}
		if(onindex == '\n')
		{
			line_count++;
		}

		index++;
	}

	return line_count;
}

char* take_word(char* str, int which_word, int fd)
{
	int word_index = 1;
	int index = 0;
	int len = 0;
	char onindex;
	int str_index = 0;
	while(word_index <= which_word)
	{
		onindex = str[str_index];
		if(onindex == ' ' || onindex == '\0')
		{
			
			if(word_index + 1 == which_word)
			{
				len = index + 1;
				index = 0;
			}
			else
			{
				index++;
			}
			word_index++;
		}
		else
		{
			index++;
		}
		str_index++;
	}
	
	char* buffer = malloc(sizeof(char)* (index));
	if(buffer == NULL)
	{
		close(fd);
		exit(12);
	}
	for(int i = 0; i < index; i++, len++)
	{
		buffer[i] = str[len];
	}
	buffer[index - 1] = '\0';
	return buffer;
}

int words_count(char* str)
{
	int words_count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			words_count++;
		}
	}
	words_count++;
	return words_count;
}

int main(int argc, char** argv)
{
	
	
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Opne faild");
		exit(1);
	}
	
	int lines = lines_count(fd);
	int lines_index = 1;
	while(lines_index <= lines)
	{
		pid_t pid = fork();
		if(pid == -1)
		{
			puts("frok faild");
			close(fd);
			exit(2);
		}
		
		if(pid == 0)
		{
			char* next_line = take_line(fd, lines_index);	
			
			int word_cnt = words_count(next_line);
			
			char* args[word_cnt + 1];
			int word_index = 1;
			while(word_index <= word_cnt)
			{
				args[word_index - 1] = take_word(next_line, word_index, fd);
				word_index++;
			}
			args[word_cnt] = NULL;
			for(int i = 0; i < word_cnt; i++)
			{
				printf("%s\t", args[i]);
			}
			
			
			char* command = args[0];
			//printf("len is :%d\n", strlen(args[0]));
		
			int err = execvp(args[0], args);
			if(err == -1)
			{
				puts("exec faild");
				
				close(fd);
				exit(3);
			}
			
			
			
		}
		else
		{
			int wstatus;
			wait(&wstatus);
			
			if(WIFEXITED(wstatus))
			{
				int status = WEXITSTATUS(wstatus);
			
				printf("exit status %s is: %d\n", take_line(fd, lines_index), status);
			}
			 
		}		
		lines_index++;
	}	
	close(fd);
	return 0;

}
