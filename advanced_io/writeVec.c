#include <fcntl.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	struct iovec iovs[3];
	char *filepath = "/tmp/devise";

	int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1) {
		perror("Open file to write");
		return EXIT_FAILURE;
	}

	char *buf[] = {
		"Bellicae Virtutis Praemium\n",
		"Honneur et Patrie\n",
		"Liberte Egalite Fraternite\n"
	};

	int i;
	for (i = 0; i < 3; i++ ) {
		iovs[i].iov_base = buf[i];
		iovs[i].iov_len = strlen(buf[i]) + 1;
	}

	ssize_t nr = writev(fd, iovs, 3);
	if ( nr == -1 ) {
		perror("Call writev");
		return EXIT_FAILURE;
	}

	printf("Write %d bytes to %s.\n", (int) nr, filepath);

	if (close(fd)) {
		perror("Close file");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
