//exit, read, write, close
#include <unistd.h>

// open:
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>

// printf:
#include<stdio.h>
// exit
#include<stdlib.h>

int main(int argc, char * argv[]) {
	int fd = open("numbers", O_RDONLY);
	if ( -1 == fd ) {
		printf("numbers file could not be opened :/\n");
		exit(1);
	}

	int read_status;
	int number;
	for (unsigned short int iterator = 0; iterator < 13; iterator++ ) {
		read_status = read(fd, &number, sizeof(int));
		if (sizeof(int) != read_status) {
			printf("Error while reading at possition %d\n", iterator);
			exit(2);
		}
		printf("Number %d has value %d\n", iterator, number);
	}
	
	close(fd);
	exit(0);
}
