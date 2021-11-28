#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define KBSIZE 1024
#define MBSIZE KBSIZE*KBSIZE

int main() {
	void *p = mmap(NULL, 1 * MBSIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (p == MAP_FAILED) {
		perror("mmap");
		return EXIT_FAILURE;
	}

	printf("Anonymous memory mapping of %d bytes created.\n", 1 * MBSIZE);
	
	if(munmap(p, 1 * MBSIZE)) {
		perror("munmap");
		return EXIT_FAILURE;
	}

	printf("Anonymous memory unmapped.\n");

	return EXIT_SUCCESS;
}
