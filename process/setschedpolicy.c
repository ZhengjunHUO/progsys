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

	sp.sched_priority = 2;
	if(sched_setparam(0, &sp)) {
		perror("setparam");
		return EXIT_FAILURE;
	}

	struct sched_param spbis;
	if(sched_getparam(0, &spbis)) {
		perror("setparam");
		return EXIT_FAILURE;
	}

	printf("Set priority to %d!\n", spbis.sched_priority);

	return EXIT_SUCCESS;
}
