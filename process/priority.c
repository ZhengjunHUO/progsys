#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>
#include <errno.h>

#define INCREM_VALUE 5

int main() {
	printf("Init nice value is %d.\n", getpriority(PRIO_PROCESS, 0));

	errno = 0;
	printf("Increase it by %d.\n", INCREM_VALUE);
	int ret = nice(INCREM_VALUE);
	if (ret == -1 && errno != 0) {
		perror("nice");
		return EXIT_FAILURE;
	}

	printf("Current nice value is %d.\n", ret);
	return EXIT_SUCCESS;
}
