#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define REQUESTSIZE 25

int main() {
	char* c = calloc(REQUESTSIZE, sizeof(char));
	if(!c) {
		perror("calloc");
		return EXIT_FAILURE;
	}

	char *m = malloc(REQUESTSIZE * sizeof(char));
	if(!m) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	printf("calloc %ld (request: %d) bytes.\n", malloc_usable_size(c), REQUESTSIZE);
	printf("malloc %ld (request: %d) bytes.\n", malloc_usable_size(m), REQUESTSIZE);

	free(c);
	free(m);
	return EXIT_SUCCESS;
}
