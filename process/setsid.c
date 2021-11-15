#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	if(!fork()) {
		printf("[Child] pid: %d\n", getpid());
		printf("[Child] Create new session.\n");
		pid_t pid = setsid();
		if ( pid == -1 ) {
			perror("setsid");
			exit(EXIT_FAILURE);
		}

		printf("[Child] session id: %d\n", pid);
		exit(EXIT_SUCCESS);
	}

	printf("[Parent] pid: %d\n", getpid());
	pid_t sid = getsid(0);
	if (sid == -1) {
		perror("getsid");
		exit(EXIT_FAILURE);
	}

	printf("[Parent] session id: %d\n", sid);
	exit(EXIT_SUCCESS);
}
