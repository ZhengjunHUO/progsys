#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return EXIT_FAILURE;
	}

	if (pid == 0) {
		char* const argv[] = {"ls", "-l", "/etc/hosts", NULL};
		int ret = execv("/bin/ls", argv);

		if (ret == -1) {
			perror("execv");
			exit(EXIT_FAILURE);
		}
	}

	int status;
	pid_t retpid;
    WLABEL:retpid = waitpid(pid, &status, WNOHANG);
	if (retpid == -1) {
		perror("waitpid");
		return EXIT_FAILURE;
	}

	if (retpid == 0) {
		printf("[Parent] Wait a second, child has not returned yet...\n");
		sleep(1);
		goto WLABEL;
	}
	
	printf("[Parent] Child %d: ", retpid);
	if (WIFEXITED(status))
		printf("Normal exit with status %d\n", WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		printf("Terminated by signal %d%s\n", WTERMSIG(status), WCOREDUMP(status) ? " [Core Dump]":"");
	if (WIFSTOPPED(status))
		printf("Stopped by signal %d\n", WSTOPSIG(status));
	if (WIFCONTINUED(status))
		printf("Continued\n");

	return EXIT_SUCCESS;
}
