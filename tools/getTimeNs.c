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

	char *clocksname[5] = {
		"CLOCK_REALTIME",
		"CLOCK_MONOTONIC",
		"CLOCK_MONOTONIC_RAW",
		"CLOCK_PROCESS_CPUTIME_ID",
		"CLOCK_THREAD_CPUTIME_ID"
	};

	int i;
	struct timespec ts;

	for(i=0; i<5; i++) {
		if(clock_gettime(allclocks[i], &ts)) {
			perror("clock_gettime");
			return EXIT_FAILURE;
		}

		printf("Clock [%s]'s current time: %ld sec %ld nanosec.\n", clocksname[i], ts.tv_sec, ts.tv_nsec);
	}

	return EXIT_SUCCESS;
}
