#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sighandler(int sig) {
	if (sig == SIGINT)
		printf("SIGINT(No: %d) raised by user!\n", sig);

	if (sig == SIGTSTP)
		printf("SIGTSTP(No: %d) raised by user!\n", sig);

	if (sig == SIGCONT)
		printf("SIGCONT(No: %d) caught!\n", sig);

	exit(EXIT_SUCCESS);
}

int main() {
	// user press Ctrl + c
	if (signal(SIGINT, sighandler) == SIG_ERR ) {
		fprintf(stderr, "Failed to register signal handler!\n");
		return EXIT_FAILURE;
	}

	// user press Ctrl + z
	if (signal(SIGTSTP, sighandler) == SIG_ERR ) {
		fprintf(stderr, "Failed to register signal handler!\n");
		return EXIT_FAILURE;
	}

	// kill -SIGSTOP then kill -SIGCONT will invoke the handler
	if (signal(SIGCONT, sighandler) == SIG_ERR ) {
		fprintf(stderr, "Failed to register signal handler!\n");
		return EXIT_FAILURE;
	}

	pause();

	return EXIT_SUCCESS;
}
