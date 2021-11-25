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

	// (3) read events
	int p = 0;
	char buf[BUF_SIZE];
	ssize_t ret = read(fd, buf, BUF_SIZE);

	while(p < ret) {
		struct inotify_event *event = (struct inotify_event *) &buf[p];
		printf("**********\nEvent detail:\nwd: %d; mask: %d; cookie: %d\n", event->wd, event->mask, event->cookie);
		if(event->len){
			printf("filename: %s (length: %d)\n", event->name, event->len);
		}

		p += sizeof(struct inotify_event) + event->len;
	}

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
