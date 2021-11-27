#include <stdlib.h>
#include <stdio.h>

void * xmalloc0(size_t size) {
	void *p = calloc(1, size);
	if(!p) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	return p;
}
