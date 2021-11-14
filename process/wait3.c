#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
	if (!fork()) {
		char* const argv[] = {"wc", "-l", "/etc/passwd", NULL};
		int ret = execv("/bin/wc", argv);

		if (ret == -1) {
			perror("execv");
			exit(EXIT_FAILURE);
		}
	}

	int status;
	pid_t pid;
    pid = wait3(&status, 0, NULL);
	if (pid == -1) {
		perror("wait3");
		return EXIT_FAILURE;
	}
	
	printf("[Parent] Child %d: ", pid);
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
