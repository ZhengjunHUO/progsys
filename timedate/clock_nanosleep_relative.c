#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct timespec ts = {2, 500000000};
	if (clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, NULL)) {
		perror("clock_nanosleep");
		return EXIT_FAILURE;
	}

	printf("Slept for 2.5 secs!\n");
	return EXIT_SUCCESS;
}
