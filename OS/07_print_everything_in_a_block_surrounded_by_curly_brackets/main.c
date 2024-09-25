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
	int fd = open("blocks", O_RDONLY);
	if ( -1 == fd ) {
		printf("blocks file could not be opened :/\n");
		exit(1);
	}

	char chunk[32];
	int bytes_read;
	int are_we_in_a_block = 0;
	while (sizeof(chunk) == (bytes_read = read(fd, chunk, sizeof(chunk)))) {
		for (unsigned int iterator = 0; iterator < sizeof(chunk); iterator++) {
			if (chunk[iterator] == '{' ) {
				// We have entered a new block!
				are_we_in_a_block += 1;
			}

			if (are_we_in_a_block >= 1) {
				printf("%c", chunk[iterator]);
			}

			if (chunk[iterator] == '}' ) {
				// an indication a block is being closed!
				are_we_in_a_block -= 1;
				// But what if we ware not in a block?
				if (are_we_in_a_block < 0) {
					are_we_in_a_block = 0;
				}
			}
		}
	}
	if ( -1 == bytes_read ) {
		printf("There was an error while reading\n");
		exit(1);
	}
	// Parse the last chunk :)
	for (unsigned int iterator = 0; iterator < bytes_read; iterator++) {
		if (chunk[iterator] == '{' ) {
			// We have entered a new block!
			are_we_in_a_block += 1;
		}

		if (are_we_in_a_block >= 1) {
			printf("%c", chunk[iterator]);
		}

		if (chunk[iterator] == '}' ) {
			// an indication a block is being closed!
			are_we_in_a_block -= 1;
			// But what if we ware not in a block?
			if (are_we_in_a_block < 0) {
				are_we_in_a_block = 0;
			}
		}
	}
	
	close(fd);
	exit(0);
}
