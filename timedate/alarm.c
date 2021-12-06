#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void myhandler(int signo) {
	printf("[%s] At the end of 3 seconds.\n", sys_siglist[signo]);
}

int main() {
	if (signal(SIGALRM, myhandler) == SIG_ERR) {
		perror("signal");
		return EXIT_FAILURE;
	}

	alarm(3);
	pause();

	return EXIT_SUCCESS; 
}
