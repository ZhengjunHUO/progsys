#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/sysinfo.h>

int main() {
	cpu_set_t set;
	CPU_ZERO(&set);

	if (sched_getaffinity(0, sizeof(cpu_set_t), &set) == -1 ) {
		perror("getaffinity");
		return EXIT_FAILURE;
	}
	
	int i, b;
	for (i=0; i<get_nprocs(); i++) {
		b = CPU_ISSET(i, &set);
		printf("CPU #%d is %s\n", i, b ? "set":"unset");
	}
	
	return EXIT_SUCCESS;
}
