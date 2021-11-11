#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int get_inode(int fd) {
	struct stat st;

	if (fstat(fd, &st) == -1) {
		perror("fstat");
		return -1;
	}

	return st.st_ino;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <FILENAME>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		perror("open");
		return EXIT_FAILURE;
	}

	int ind = get_inode(fd);
	if (ind == -1) {
		return EXIT_FAILURE;
	}

	printf("Inode of %s: %d\n", argv[1], ind);	
	return EXIT_SUCCESS;
}
