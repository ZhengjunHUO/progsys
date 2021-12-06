#include <sys/time.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void myhandler(int signo) {
	printf("Signal[%s] caught!\n", sys_siglist[signo]);
}

int main() {
	struct itimerval it;
	signal(SIGALRM, myhandler);

	it.it_value.tv_sec = 1;
	it.it_value.tv_usec = 0;
	it.it_interval.tv_sec = 3;
	it.it_interval.tv_usec = 0;

	if(setitimer(ITIMER_REAL, &it, NULL)) {
		perror("setitimer");
		return EXIT_FAILURE;
	}

	while(1)
		pause();

	return EXIT_SUCCESS;
}
