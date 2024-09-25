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
	int fd = open("testfile", O_RDWR);
	if ( -1 == fd ) {
		printf("Could not open testfile!");
		exit(1);
	}

	// === 1)
	printf("Cursor's possition immediatelly after opening the file:\n");
	int possition = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", possition);
	
	// === 2)
	printf("Cursor's possition after reading 5 bytes from the file:\n");
	char buffer[5];
	if ( 5 != read(fd, buffer, 5) ) {
		printf("There was a problem with reading from testfile\n");
		exit(2);
	}
	possition = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", possition);

	// === 3)
	printf("Cursor's possition after writing 6 bytes to the file:\n");
	if ( 6 != write(fd, "konche", 6) ) {
		printf("There was a problem writing to the file:\n");
		exit(3);
	}
	possition = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", possition);

	// === 4)
	printf("Cursor's possition after moving it forward with offset 3:\n");
	possition = lseek(fd, 3, SEEK_CUR);
	printf("%d\n", possition);

	// === 5)
	printf("Cursor's possition after moving it to the end of the file:\n");
	possition = lseek(fd, 0, SEEK_END);
	printf("%d\n", possition);

	// === 6)
	printf("Cursor's possition after moving it to the 15th possition:\n");
	possition = lseek(fd, 15, SEEK_SET);
	printf("%d\n", possition);

	// === 7)
	printf("Cursor's possition after moving it 15 possitions after the end of the file:\n");
	possition = lseek(fd, 15, SEEK_END);
	printf("%d\n", possition);

	// === 8)
	printf("Cursor's possition after moving it with negative 9 offset relative to it's CURRENT possition:\n");
	possition = lseek(fd, -9, SEEK_CUR);
	printf("%d\n", possition);

	// === 9)
	printf("Cursor's possition after moving it with negative 3 offset relative to the file's end:\n");
	possition = lseek(fd, -3, SEEK_END);
	printf("%d\n", possition); 

	// === 10)
	printf("Opening a new file descriptor to the same file...\n");
	int fd2 = open("testfile", O_RDWR);
	printf("New file descriptor's cursor's possition:\n");
	int new_possition = lseek(fd2, 0, SEEK_CUR);
	printf("%d\n", new_possition);

	// === 11)
	printf("================\n");
	printf("Fd1: %d, Fd2: %d\n", possition, new_possition);
	printf("Reading a byte from the first file descriptor...\n");
	if ( 1 != read(fd, buffer, 1) ) {
		printf("Could not read\n");
		exit(3);
	}
	possition = lseek(fd, 0, SEEK_CUR);
	new_possition = lseek(fd2, 0, SEEK_CUR);
	printf("Fd1: %d, Fd2: %d\n", possition, new_possition);
	printf("Reading 3 bytes from the 2nd file descriptor...\n");
	if ( 3 != read(fd2, buffer, 3) ) {
		printf("Could not read\n");
		exit(4);
	}
	possition = lseek(fd, 0, SEEK_CUR);
	new_possition = lseek(fd2, 0, SEEK_CUR);
	printf("Fd1: %d, Fd2: %d\n", possition, new_possition);

	// Release the dynamically allocated resources we no longer need:
	close(fd);
	close(fd2);
	exit(0);
}
