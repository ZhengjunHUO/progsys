#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int system2(char *const command) {
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return -1;
	}

	if (!pid) {
		char *const argv[] = {"sh", "-c", command, NULL};
		execv("/bin/sh", argv);
		exit(-1);	
	}

	int status;
	if (waitpid(pid, &status, 0) == -1) {
		perror("waitpid");
		return -1;
	}

	if(WIFEXITED(status))
		return WEXITSTATUS(status);

	return -1;
}

int main() {
	return system2("w");
}
