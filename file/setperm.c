#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: %s </PATH/TO/FILE>\n", argv[0]);
		return EXIT_FAILURE;
	}

	if (chmod(argv[1], S_IRUSR | S_IWUSR)) {
		perror("chmod");
		return EXIT_FAILURE;
	}

	printf("Change %s's mode to 600.\n", argv[1]);
	return EXIT_SUCCESS;
}
