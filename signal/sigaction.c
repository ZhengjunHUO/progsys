#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_handler(int signo, siginfo_t *si, void *ucontext) {
	printf("Catch signal [%s] with payload %d. (context: \"%s\")!\n", sys_siglist[signo], si->si_int, (char*)ucontext);
	exit(EXIT_SUCCESS);
}

int main() {
	struct sigaction action;
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = my_handler;

	if(sigaction(SIGUSR2, &action, NULL)){
		perror("sigaction");	
		return EXIT_FAILURE;
	}

	printf("My pid: %d\n", getpid());
	pause();
	return EXIT_SUCCESS;
}
