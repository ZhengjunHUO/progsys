#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <PID>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// convert argv[1] to int
	char *p;
	long conv = strtol(argv[1], &p, 10);
	if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
		fprintf(stderr, "Illegal pid input!\n");
		return EXIT_FAILURE;
	}
	int pidno = conv;

	// send signal with payload
	union sigval payload;
	payload.sival_int = 666;

	if(sigqueue(pidno, SIGUSR2, payload)) {
		perror("sigqueue");
		return EXIT_FAILURE;
	}

	printf("Signal with payload sent to %s!\n", argv[1]);
	return EXIT_SUCCESS;
}
