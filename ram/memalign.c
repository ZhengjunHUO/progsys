#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
	void *buf;

	int ret = posix_memalign(&buf, 512, 4096);
	if(ret) {
		fprintf(stderr, "posix_memalign: %s\n", strerror(ret));
		return EXIT_FAILURE;	
	}

	printf("Allocate %ld (request: 4096) bytes, aligned on 512-byte.\n", malloc_usable_size (buf));
	free(buf);

	return EXIT_SUCCESS;
}
