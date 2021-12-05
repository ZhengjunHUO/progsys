#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct timespec req = {0, 500};
	if (nanosleep(&req, NULL)) {
		perror("nanosleep");
		return EXIT_FAILURE;
	}

	printf("Sleep for 500 nanoseconds\n");
	return EXIT_SUCCESS;
}
