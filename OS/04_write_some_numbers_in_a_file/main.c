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
	// We want to make sure the file is empty before we start writing our numbers in it.
	int fd = open("numbers", O_WRONLY | O_TRUNC );
	if ( -1 == fd ) {
		printf("numbers file could not be opened :/\n");
		exit(1);
	}

	int numbers_to_be_written[13] = { 8, 200, 3000, 4444, 55555, 600, 70000, 800000, 9, 101010,11, 1212, 133331 };

	int write_status;
	for ( unsigned short int counter = 0; counter < 13; ++counter ) {
if ( sizeof(int) != ( write_status = write(fd, &numbers_to_be_written[counter], sizeof(int)))) {
			printf("Problem with write on index %d\n", counter);
			close(fd);
			exit(2);
		} 
	}
	/*
	// Alternatively, we can write the write function as:
	if (sizeof(numbers_to_be_written) != write(fd, numbers_to_be_written, sizeof(numbers_to_be_written))) {
		printf("Problem with write\n");
		exit(3);
	}
	// This way we will reduce the number of "write" calls we make and thus make the code
	// run faster.
	*/

	// Release the dynamically allocated resources after we no longer need them:
	close(fd);
	exit(0);
}
