#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts)) {
		perror("clock_gettime");
		return EXIT_FAILURE;
	}

	ts.tv_sec += 3;
	printf("Sleep until %lds %ldns (uptime)\n", ts.tv_sec, ts.tv_nsec);

	if (clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &ts, NULL)) {
		perror("clock_nanosleep");
		return EXIT_FAILURE;
	}

	printf("Done!\n");
	return EXIT_SUCCESS;
}
