#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int get_rr_interval(pid_t pid) {
	struct timespec ts;
	if(sched_rr_get_interval(pid, &ts)) {
		perror("sched_rr_get_interval");
		return -1;
	}

	printf("Timeslice allocated to process is %.2lf milliseconds\n", (ts.tv_sec * 1000.0f) + (ts.tv_nsec / 1000000.0f));
	return 0;
}

/*
int main() {
	if(get_rr_interval(0))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
*/
