#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	printf("Running with pid: %d\n", getpid());
	int ret;

	do{
		ret = system("pidof vim");
		if (WIFSIGNALED(ret)) {
			printf("Terminated by signal %d%s\n", WTERMSIG(ret), WCOREDUMP(ret) ? " [Core Dump]":"");
			break;
		}
	}while(1);

	printf("Quit!\n");
	return EXIT_SUCCESS;
}
