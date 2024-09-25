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
	int fd = open("data", O_RDONLY);
	if ( -1 == fd ) {
		printf("there was a problem openning data file\n");
		exit(1);
	}

	char buffer;
	int read_status;
	int write_status;
	// read will return:
	// -1 on failure
	// 0 if there are no more bytes to be read
	// 1 if it manages to read a byte
	while ( 1 == (read_status = read(fd, &buffer, 1) ) ) {
		// write will return:
		// -1 on failure
		// 0 if it is unable to write 1 byte to STDOUT
		// 1 on success
		char b = buffer;
		if ( 1 != (write_status = write(1, &b, 1) ) ) {
			printf("Could not write :/\n");
			close(fd);
			exit(1);
		}
	}
	if (-1 == read_status) {
		printf("there was a problem with reading from data file\n");
		close(fd);
		exit(2);
	}

	// Release the dynamically allocated resources we no longer need:
	close(fd);
	exit(0);
}
