#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

#define BUF_SIZE 4096

int main() {
	void *buf = xmalloc0(BUF_SIZE);

	printf("Xmalloc success!\n");
	printmallinfo();
	free(buf);

	return EXIT_SUCCESS;
}
