#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	// init inotify instance to fd
	int fd = inotify_init1(0);
	if (fd == -1) {
		perror("inotify_init1");
		return EXIT_FAILURE;
	}

	printf("inotify instance created with fd[%d]\n", fd);

	if(close(fd)) {
		perror("close");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
