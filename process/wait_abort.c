#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	// Child process, send SIGABRT to itself
	if (!fork())
		abort();

	// Parent process, wait and query the child's status
	int status;
	pid_t pid = wait(&status);
	if (pid == -1) {
		perror("wait");
		return EXIT_FAILURE;
	}

	printf("Child[%d]: ", pid);
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
