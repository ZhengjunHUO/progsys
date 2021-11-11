#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
	if ( argc < 2 ) {
		fprintf(stderr, "Usage: %s <FILENAME>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// open file
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("Open file");
		return EXIT_FAILURE;
	}

	// Process will read the entire file, perform aggressive readahead
	if (posix_fadvise(fd, 0, 0, POSIX_FADV_SEQUENTIAL) == -1)
		perror("posix_fadvise");

	struct stat st;
	if(fstat(fd, &st) == -1){
		perror("fstat file");
		return EXIT_FAILURE;
	}

	// Print file
	char buf[BUFFER_SIZE];
	int len = st.st_size;
	ssize_t nr;

	while (len != 0 && (nr = read(fd, buf, BUFFER_SIZE)) != 0) {
		if (nr == -1) {
			if (errno == EINTR)
				continue;
			perror("read");
			break;
		}

		len -= nr;
	}

	// Close fd
	if(close(fd)) {
		perror("Close fd");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
