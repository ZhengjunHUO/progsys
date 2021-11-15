#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	if(!fork()) {
		printf("My real uid: %d\n", getuid());
		printf("My real gid: %d\n", getgid());

		printf("My effective uid: %d\n", geteuid());
		printf("My effective gid: %d\n", getegid());

		if(seteuid(1001)) {
			perror("seteuid");
			exit(EXIT_FAILURE);
		}

		printf("Set effective uid to 1001!\n");
		printf("My real uid: %d\n", getuid());
		printf("My effective uid: %d\n", geteuid());

		int fd = creat("/tmp/helloworld", 0644);
		if ( fd == -1 ) {
			perror("creat");
			exit(EXIT_FAILURE);
		}

		printf("Create file /tmp/helloworld!\n");

		if(close(fd)) {
			perror("close");
			exit(EXIT_FAILURE);
		}
	
		exit(EXIT_SUCCESS);
	}

	int status;
	pid_t pid = wait(&status);
	if (pid == -1) {
		perror("wait");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
