#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return EXIT_FAILURE;
	}

	// Child process, send SIGABRT to itself
	if (!pid)
		abort();

	// Parent process, wait and query the child's status
	int status;
	pid_t retpid = wait4(pid, &status, 0, NULL);
	if (retpid == -1) {
		perror("wait");
		return EXIT_FAILURE;
	}

	printf("Child[%d]: ", retpid);
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
