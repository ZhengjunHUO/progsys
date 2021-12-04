#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	clockid_t allclocks[5] = {
		CLOCK_REALTIME,
		CLOCK_MONOTONIC,
		CLOCK_MONOTONIC_RAW,
		CLOCK_PROCESS_CPUTIME_ID,
		CLOCK_THREAD_CPUTIME_ID
	};

	int i;
	struct timespec res;

	for(i=0; i<5; i++) {
		if(clock_getres(allclocks[i], &res)) {
			perror("clock_getres");
			return EXIT_FAILURE;
		}

		printf("Clock [%d]'s resolution: %ld sec %ld nanosec.\n", allclocks[i], res.tv_sec, res.tv_nsec);
	}

	return EXIT_SUCCESS;
}
