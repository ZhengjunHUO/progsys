#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
	int fd = open("/tmp/helloworld", O_RDONLY, 0664);
	if (fd == -1) {
		const int err = errno;
		fprintf(stderr, "Open file failed: %s [%d]\n", strerror(err), err);
		return EXIT_FAILURE;
	}

	char buf[BUFFER_SIZE];
	ssize_t nr;

	nr = read(fd, &buf, BUFFER_SIZE);
	if ( nr == -1 ) {
		const int err = errno;
		fprintf(stderr, "Error reading file : %s [%d]\n", strerror(err), err);
		return EXIT_FAILURE;
	}

	printf("Read from file: \n%s\n", buf);

	close(fd);
	return EXIT_SUCCESS;
}
