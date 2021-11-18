#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include "schedpolicy.h"

int main() {
	printf("Initailly: ");
	if(get_sched_policy(0)) {
		return EXIT_FAILURE;
	}

	struct sched_param sp = { .sched_priority = 1 };
	if (sched_setscheduler(0, SCHED_FIFO, &sp)) {
		perror("setscheduler");
		return EXIT_FAILURE;
	}

	printf("After set: ");
	if(get_sched_policy(0)) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
