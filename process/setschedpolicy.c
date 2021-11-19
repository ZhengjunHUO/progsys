#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include "schedpolicy.h"

int main() {
	// Get current process scheduling policy
	printf("Initailly: ");
	if(get_sched_policy(0))
		return EXIT_FAILURE;

	// Set current process scheduling policy to RoundRobin with priority == 1
	struct sched_param sp = { .sched_priority = 1 };
	if (sched_setscheduler(0, SCHED_RR, &sp)) {
		perror("setscheduler");
		return EXIT_FAILURE;
	}

	// Check the change
	printf("After set: ");
	if(get_sched_policy(0))
		return EXIT_FAILURE;

	// Get timeslice allocated under the RR policy
	if(get_rr_interval(0))
		return EXIT_FAILURE;

	// Set the priorty to 2
	sp.sched_priority = 2;
	if(sched_setparam(0, &sp)) {
		perror("setparam");
		return EXIT_FAILURE;
	}

	// Check the change
	struct sched_param spbis;
	if(sched_getparam(0, &spbis)) {
		perror("setparam");
		return EXIT_FAILURE;
	}

	printf("Set priority to %d!\n", spbis.sched_priority);

	return EXIT_SUCCESS;
}
