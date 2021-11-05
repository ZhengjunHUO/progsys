#include <sys/uio.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char *filepath = "/tmp/devise";

	int fd = open(filepath, O_RDONLY);
	if (fd == -1) {
		perror("Read file");
		return EXIT_FAILURE;
	}

	struct iovec iovs[3];
	char bb[28], np[19], rp[28]; 

	iovs[0].iov_base = bb;
	iovs[1].iov_base = np;
	iovs[2].iov_base = rp;
	iovs[0].iov_len = sizeof(bb);
	iovs[1].iov_len = sizeof(np);
	iovs[2].iov_len = sizeof(rp);

	ssize_t nr = readv(fd, iovs, 3);
	if ( nr == -1 ) {
		perror("Read from file");
		return EXIT_FAILURE;
	}

	int i;
	for (i = 0; i < 3; i++) {
		printf("In buffer %d: %s", i, (char *)iovs[i].iov_base);
	}

	if (close(fd)) {
		perror("Close file");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
