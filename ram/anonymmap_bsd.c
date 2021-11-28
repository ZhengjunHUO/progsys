#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd = open("/dev/zero", O_RDWR);
	if (fd < 0) {
		perror("open");
		return EXIT_FAILURE;
	}

	void *p = mmap(NULL, 4 * getpagesize(), PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (p == MAP_FAILED) {
		perror("mmap");
		if (close(fd))
			perror("close");
		return EXIT_FAILURE;
	}

	printf("Anonymous memory mapping of 4 pages (%d bytes) created.\n", 4 * getpagesize());

	if (close(fd))
		perror("close");
	
	if (munmap(p, 4 * getpagesize())) {
		perror("munmap");
		return EXIT_FAILURE;
	}

	printf("Anonymous memory unmapped.\n");

	return EXIT_SUCCESS;
}
