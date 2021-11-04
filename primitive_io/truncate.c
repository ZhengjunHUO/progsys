#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
	int fd = open("/tmp/helloworld", O_WRONLY | O_SYNC, 0664);
	if (fd == -1) {
		const int err = errno;
		fprintf(stderr, "Open file failed: %s [%d]\n", strerror(err), err);
		return EXIT_FAILURE;
	}

	int res = ftruncate(fd, 50);
	if (res == -1) {
		const int err = errno;
		fprintf(stderr, "Error truncating file : %s [%d]\n", strerror(err), err);
		close(fd);
		return EXIT_FAILURE;
	}

	printf("File truncated\n");

	if (close(fd) == -1) {
		perror ("Close file failed!");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
