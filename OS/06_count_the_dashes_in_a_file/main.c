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
	int fd = open("text", O_RDONLY);
	if ( -1 == fd ) {
		printf("text file could not be opened :/\n");
		exit(1);
	}

	char chunk[16];
	int bytes_read;
	unsigned int dashes_found = 0;
	while (sizeof(chunk) == (bytes_read = read(fd, chunk, sizeof(chunk)))) {
		for (unsigned int iterator = 0; iterator < sizeof(chunk); iterator++) {
			if ( chunk[iterator] == '-' ) {
				dashes_found += 1;
			}
		}
	}
	if ( -1 == bytes_read ) {
		printf("There was an error while reading\n");
		close(fd);
		exit(1);
	}
	// Parse the last chunk :)
	for (unsigned int iterator = 0; iterator < bytes_read; iterator++) {
		if ( chunk[iterator] == '-' ) {
			dashes_found += 1;
		}
	}

	printf("The number of dashes in the text file is: %d\n", dashes_found);
	
	close(fd);
	exit(0);
}
