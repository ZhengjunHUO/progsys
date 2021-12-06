#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct timeval tv = {2, 500000};
	printf("Sleep for 2.5 secs\n");

	if (select(0, NULL, NULL, NULL, &tv) == -1) {
		perror("select");
		return EXIT_FAILURE;
	}

	printf("Done!\n");
	return EXIT_SUCCESS;
}
