#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	if(!fork()) {
		return 5;	
	}

	siginfo_t infop;
	int ret = waitid(P_ALL, (id_t)0, &infop, WEXITED|WSTOPPED);
	if (ret == -1) {
		perror("waitid");
		return EXIT_FAILURE;
	}

	printf("Child %d: ", infop.si_pid);
	if (infop.si_code == CLD_EXITED)
		printf("exited with code %d.\n", infop.si_status);
	if (infop.si_code == CLD_KILLED)
		printf("killed by signal %d.\n", infop.si_status);
	if (infop.si_code == CLD_STOPPED)
		printf("stopped by signal %d.\n", infop.si_status);

	return EXIT_SUCCESS;
}
