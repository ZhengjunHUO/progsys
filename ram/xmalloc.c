#include <stdlib.h>
#include <stdio.h>

void * xmalloc(size_t size) {
	void *p = malloc(size);
	if(!p) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	return p;
}
