#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
	int err;
	int fd = open("/tmp/helloworld", O_RDWR | O_SYNC, 0664);
	if (fd == -1) {
		err = errno;
		fprintf(stderr, "Open file failed: %s [%d]\n", strerror(err), err);
		return EXIT_FAILURE;
	}

	const char *str = "Fufu is a five-year-old cat.";
	ssize_t res = pwrite(fd, str, strlen(str), 13);
	if (res == -1) {
		err = errno;
		fprintf(stderr, "Pwrite to file failed: %s [%d]\n", strerror(err), err);
		close(fd);
		return EXIT_FAILURE;
	} 
	printf("[INFO] PWrite to file, the file position should not be changed.\n");

	off_t pos = lseek(fd, 0, SEEK_CUR); 
	if (pos != -1)
		printf("[INFO] File's current postion at: %zu\n", pos);

	char buf[BUFFER_SIZE];
	off_t offset = 6;
	res = pread(fd, &buf, BUFFER_SIZE, offset);  
	if (res == -1) {
		err = errno;
		fprintf(stderr, "Pread from file failed: %s [%d]\n", strerror(err), err);
		close(fd);
		return EXIT_FAILURE;
	} 
	printf("[INFO] PRead from file at offset %zu: \n%s\n", offset, buf);

	printf("[INFO] Read from file's current postion...\n");
	res = read(fd, &buf, BUFFER_SIZE);
	if ( res == -1 ) {
		err = errno;
		fprintf(stderr, "Reading file failed: %s [%d]\n", strerror(err), err);
		close(fd);
		return EXIT_FAILURE;
	}
	printf("%s\n", buf);

	if (close(fd) == -1) {
		perror ("Close file failed!");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
