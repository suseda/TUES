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
	// Flags: O_WRONLY, O_RDWD, O_CREAT, O_TRUNC, <mode>
	int file_descriptor = open("first_file", O_RDONLY);
	if ( -1 == file_descriptor ) {
		printf("Unable to open first_file");
		exit(1);
	}

	char symbol;
	int read_status = read(file_descriptor, &symbol, 1);
	if ( -1 == read_status) {
		printf("Read failed!");
		close(file_descriptor);
		exit(2);
	}
	if ( 0 == read_status ) {
		printf("Read was unable to read a byte from the file");
		close(file_descriptor);
		exit(3);
	}
	if ( 1 != read_status) {
		printf("We will never get here :)");
		exit(4);
	}

	// 1 = STDOUT.
	printf("Procheteniqt simvol e:\n");
	int write_status = write(1, &symbol, 1);
	printf("\n");
	if ( -1 == write_status ) {
		printf("Write failed!");
		exit(5);
	}
	if ( 0 == write_status ) {
		printf("Write could not wrtie to stdout");
		exit(6);
	}
	if ( 1 != write_status ) {
		printf("We will never get here :)");
		exit(7);
	}
	
	//NB! Release the dynamically allocated resources we no longer need.
	close(file_descriptor);
	exit(0);
}
