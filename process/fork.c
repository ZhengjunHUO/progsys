#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	pid_t pid = fork();
	if (pid > 0) {
		printf("Parent[%d]: fork a child with pid[%d]!\n", getpid(), pid);	
	}else if (pid == 0) {
		printf("Child [%d]: i'm the child of process[%d]!\n", getpid(), getppid());	
	}else{
		perror("fork");
		return EXIT_FAILURE;	
	}

	return EXIT_SUCCESS;
}
