#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct timeval tv;
	if (gettimeofday(&tv, NULL)) {
		perror("gettimeofday");
		return EXIT_FAILURE;
	}

	printf("Current time since epoch is: %ld sec %ld microsec\n", tv.tv_sec, tv.tv_usec);
	return EXIT_SUCCESS;
}
