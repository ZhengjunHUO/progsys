#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/limits.h>

int main(){
	// 1) create new daemon process
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		return EXIT_FAILURE;
	}
	
	// 2) Parent exit immediately
	if (pid != 0) {
		exit(EXIT_SUCCESS);			
	}

	// 3) Child get a new session and group
	if (setsid() == -1) {
		perror("setsid");
		exit(EXIT_FAILURE);
	}

	// 4) Change the workdir to root
	if (chdir("/")) {
		perror("chdir");
		exit(EXIT_FAILURE);
	}

	printf("Daemon launched !\n");

	// 5) Close all fds
	int i;
	for (i=0; i<NR_OPEN; i++)
		close(i);

	// 6) Redirect stdin/out/err to null
	open("/dev/null", O_RDWR);
	dup(0);
	dup(0);

	sleep(300);

	exit(EXIT_SUCCESS);	
}
