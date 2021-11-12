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
		char* const argv[] = {"ping", "-c", "3", "8.8.8.8", NULL};
		int ret = execv("/bin/ping", argv);
		if (ret == -1) {
			perror("execv");
			exit(EXIT_FAILURE);
		}
	}

	int status;
    waitpid(pid, &status, 0);
	printf("[Parent]: Child %d returned, exit with success\n", pid);
	return EXIT_SUCCESS;
}
