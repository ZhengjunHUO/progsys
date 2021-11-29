#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "malloc.h"

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
	if ( argc < 2 ) {
		fprintf(stderr, "Usage: %s <FILENAME>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// open file
	int fd = open_etc_config(argv[1], O_RDONLY, 0644);
	if (fd == -1) {
		perror("Open file");
		return EXIT_FAILURE;
	}

	struct stat st;
	if(fstat(fd, &st) == -1){
		perror("fstat file");
		return EXIT_FAILURE;
	}

	// Print file
	char buf[BUFFER_SIZE];
	int len = st.st_size;
	ssize_t nr, ret;

	while (len != 0 && (nr = read(fd, buf, BUFFER_SIZE)) != 0) {
		if (nr == -1) {
			if (errno == EINTR)
				continue;
			perror("read");
			break;
		}

		len -= nr;
		ret = write(STDOUT_FILENO, buf, nr);
		if (ret == -1) {
			perror("write");
			break;
		}
	}

	// Close fd
	if(close(fd)) {
		perror("Close fd");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
