#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

#define BUF_SIZE 4096

int main() {
	void *buf = xmalloc(BUF_SIZE);

	printf("Xmalloc success!\n");
	free(buf);

	return EXIT_SUCCESS;
}
