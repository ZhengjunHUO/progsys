#include <stdlib.h>
#include <stdio.h>

int main() {
	char* c = calloc(16, sizeof(char));
	if(!c) {
		perror("calloc");
		return EXIT_FAILURE;
	}

	char *m = malloc(16*sizeof(char));
	if(!m) {
		perror("malloc");
		return EXIT_FAILURE;
	}

	printf("Calloc 16 bytes.\n");
	printf("Malloc 16 bytes.\n");

	free(c);
	free(m);
	return EXIT_SUCCESS;
}
