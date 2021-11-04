#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
	//int fd = open("/tmp/helloworld", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	int fd = creat("/tmp/helloworld", 0644);
	if (fd == -1) {
		const int err = errno;
		fprintf(stderr, "Create file failed: %s [%d]\n", strerror(err), err);
		return EXIT_FAILURE;
	}

	printf("Create file [fd: %d] successed!\n", fd);
	if (close(fd) == -1) {
		perror ("Close file failed!");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
