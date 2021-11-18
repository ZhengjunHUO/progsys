#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int getpriorange() {
	int i, min, max;
	// FIFO: 1; RR: 2;
	for (i=1; i<3; i++) {
		min = sched_get_priority_min(i);
		if (min == -1) {
			perror("sched_get_priority_min");
			return -1;
		}

		max = sched_get_priority_max(i);
		if (max == -1) {
			perror("sched_get_priority_max");
			return -1;
		}

		printf("Scheduling policy %s's priority range is %d-%d.\n", (i == SCHED_RR) ? "RR":"FIFO", min, max);
	}

	return 0;
}

int main() {
	if(getpriorange())
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
