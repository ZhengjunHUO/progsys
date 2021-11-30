#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
	void *buf;

	int ret = posix_memalign(&buf, getpagesize(), 4096);
	if(ret) {
		fprintf(stderr, "posix_memalign: %s\n", strerror(ret));
		return EXIT_FAILURE;	
	}
	printf("Allocate %ld (request: 4096) bytes at %p, aligned on %d-byte.\n", malloc_usable_size(buf), buf, getpagesize());

	if(mlock(buf, malloc_usable_size(buf)))
		perror("mlock");
	printf("Buffer locked into the memory!\n");

	if(munlock(buf, malloc_usable_size(buf)))
		perror("munlock");

	printf("Buffer unlocked from the memory!\n");

	free(buf);
	return EXIT_SUCCESS;
}
