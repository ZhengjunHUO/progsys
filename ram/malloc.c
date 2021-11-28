#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define BUF_SIZE 4096

int main() {
	void *buf = malloc(BUF_SIZE);
	if(!buf) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	printf("Malloc success!\n");
	malloc_stats();
	free(buf);

	return EXIT_SUCCESS;
}
