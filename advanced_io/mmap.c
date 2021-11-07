#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	// check if fd point to a regular file
	struct stat st;
	if(fstat(fd, &st) == -1){
		perror("fstat file");
		return EXIT_FAILURE;
	}

	if(!S_ISREG(st.st_mode)) {
		fprintf(stderr, "%s is not a regular file!\n", argv[1]);
		return EXIT_FAILURE;
	}

	// Do mapping
	char *m = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (m == MAP_FAILED) {
		perror("Mapping file to memory");
		close(fd);
		return EXIT_FAILURE;
	}

	// Close fd
	if(close(fd)) {
		perror("Close fd");
		return EXIT_FAILURE;
	}

	// Print out file content
	int i;
	for (i = 0; i < st.st_size; i++) {
		putchar(m[i]);
	}

	// Unmap
	if (munmap(m, st.st_size) == -1) {
		perror("Unmap");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
