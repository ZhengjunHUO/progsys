#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	long hz = sysconf(_SC_CLK_TCK);
	if(hz == -1) {
		perror("sysconf");
		return EXIT_FAILURE;
	}

	printf("Current HZ is: %ld\n", hz);
	return EXIT_SUCCESS;
}
