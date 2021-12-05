#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int signo, siginfo_t *si, void *ucontext) {
        printf("Catch signal [%s] (payload: \"%d\"; context: \"%s\")!\n", sys_siglist[signo], si->si_int, (char*)ucontext);
}

int main() {
        struct sigaction action;
        action.sa_flags = SA_SIGINFO;
        action.sa_sigaction = my_handler;

        if(sigaction(SIGINT, &action, NULL)){
		perror("sigaction");
                return EXIT_FAILURE;
        }

	struct timespec rqtp = {30, 0};
	struct timespec rmtp;
	printf("Process %d will sleep 30 sec ...\n", getpid());

	loop:
	if (nanosleep(&rqtp, &rmtp)) {
		if (errno == EINTR) {
			printf("Receive interrupt signal, still got %ld sec %ld nanosec to sleep ...\n", rmtp.tv_sec, rmtp.tv_nsec);
			rqtp.tv_sec = rmtp.tv_sec;
			rqtp.tv_nsec = rmtp.tv_nsec;
			goto loop;
		}
		perror("nanosleep");
		return EXIT_FAILURE;
	}

	printf("Done !\n");
	return EXIT_SUCCESS;
}
