#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/fs.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// Get number of blocks associated with fd
int get_block_nr (int fd) {
	struct stat st;

	if (fstat(fd, &st) == -1) {
		perror("fstat");
		return -1;
	}

	return st.st_blocks;
}

// Get physical block from mapping
int get_block(int fd, int i) {
	if (ioctl(fd, FIBMAP, &i) == -1) {
		perror("ioctl");
		return -1;
	}
	
	return i;
}

// Print out the searching result
void list_blocks(int fd) {
	int nr = get_block_nr(fd);
	if (nr <= 0) {
		return;
	}
	printf("File has %d block(s):\n", nr);

	int i;
	for (i=0; i<nr; i++) {
		int blk;
		blk = get_block(fd, i);
		if (blk == -1) {
			return;
		}
		if (blk == 0) {
			continue;
		}

		printf("[%d]: %d\n", i, blk);
	}
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

	list_blocks(fd);
	return EXIT_SUCCESS;
}
