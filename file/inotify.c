#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main() {
	// (1) init inotify instance to fd
	int fd = inotify_init1(0);
	if (fd == -1) {
		perror("inotify_init1");
		return EXIT_FAILURE;
	}

	printf("inotify instance created with fd[%d]\n", fd);

	// (2) attach new watch to instance
	int wd = inotify_add_watch(fd, "/tmp", IN_CREATE|IN_DELETE|IN_MODIFY);
	if (wd == -1) {
		perror("inotify_add_watch");
		close(fd);
		return EXIT_FAILURE;
	}

	printf("new watch with wd[%d] attach to inotify instance\n", wd);

	// remove watch
	if(inotify_rm_watch(fd, wd))
		perror("inotify_rm_watch");

	// close inotify instance
	if(close(fd)) {
		perror("close");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
