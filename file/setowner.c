#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: %s </PATH/TO/FILE>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// -1: don't change the owner 
	if (chown(argv[1], -1, 1001)) {
		perror("chown");
		return EXIT_FAILURE;
	}

	printf("Change %s's group to 1001.\n", argv[1]);
	return EXIT_SUCCESS;
}
