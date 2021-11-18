#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

int get_sched_policy(int pid) {
	int policy = sched_getscheduler(pid);
	if (policy == -1) {
		perror("getscheduler");
		return -1;
	}

	switch(policy) {
		case SCHED_OTHER:
			printf("Normal Scheduling Policy.\n");
			break;
		case SCHED_FIFO:
			printf("FIFO Scheduling Policy.\n");
			break;
		case SCHED_RR:
			printf("Roundrobin Scheduling Policy.\n");
			break;
		default:
			printf("Unknown Scheduling Policy.\n");
	}

	return 0;
} 

int main() {
	// Get current process's sheduling policy
	if(get_sched_policy(0)) {
		return EXIT_FAILURE;
	}
      	
	return EXIT_SUCCESS;
}
