#define _GNU_SOURCE

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <poll.h>

int main() {
	struct pollfd fds[] = {
		{ .fd = STDIN_FILENO, .events = POLLIN },
		{ .fd = STDOUT_FILENO, .events = POLLOUT }
	};

	struct timespec ts = {
		.tv_sec = 10,
		.tv_nsec = 0
	};

	int res = ppoll(fds, 2, &ts, NULL);	
	if (res == -1) {
		perror("Call ppoll failed");
		return EXIT_FAILURE;
	}
	if (res == 0) {
		printf("Nothing's ready, time out!\n");
		return EXIT_SUCCESS;
	}

	if (fds[0].revents && POLLIN)
		printf("Stdin is ready to read!\n");

	if (fds[1].revents && POLLOUT)
		printf("Stdout is ready to write!\n");

	return EXIT_SUCCESS;
}
