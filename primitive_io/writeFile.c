#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {
	int fd = open("/tmp/helloworld", O_WRONLY, 0664);
	if (fd == -1) {
		const int err = errno;
		fprintf(stderr, "Open file failed: %s [%d]\n", strerror(err), err);
		return EXIT_FAILURE;
	}

	const char *buf = "Hello System!\n";
	ssize_t nr = write(fd, buf, strlen(buf)); 

	if ( nr == -1 ) {
		const int err = errno;
		fprintf(stderr, "Error writing to file : %s [%d]\n", strerror(err), err);
		close(fd);
		return EXIT_FAILURE;
	}

	if ( nr != strlen(buf)) {
		fprintf(stderr, "Partial writes!\n");
	}

	printf("Written to file: \n%s\n", buf);

	close(fd);
	return EXIT_SUCCESS;
}
