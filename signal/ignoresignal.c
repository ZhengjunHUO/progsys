#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	// user press Ctrl + c
	if (signal(SIGINT, SIG_IGN) == SIG_ERR ) {
		fprintf(stderr, "Failed to register signal handler!\n");
		return EXIT_FAILURE;
	}

	// user press Ctrl + z
	if (signal(SIGTSTP, SIG_IGN) == SIG_ERR ) {
		fprintf(stderr, "Failed to register signal handler!\n");
		return EXIT_FAILURE;
	}

	// kill <PID>
	if (signal(SIGTERM, SIG_IGN) == SIG_ERR ) {
		fprintf(stderr, "Failed to register signal handler!\n");
		return EXIT_FAILURE;
	}

	// use # kill -SIGKILL <PID> to end this process
	pause();

	return EXIT_SUCCESS;
}
