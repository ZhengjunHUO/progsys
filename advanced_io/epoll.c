#include <sys/epoll.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_EVENTS 8

int main() {
	// 1) create epoll instance in epfd
	int epfd = epoll_create1(0);
	if (epfd == -1) {
		perror("Init epfd");
		return EXIT_FAILURE;
	}

	// 2) add monitored fd to context
	struct epoll_event event;
	event.events = EPOLLIN;
	event.data.fd = STDIN_FILENO;

	if (epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &event)) {
		perror("Regist to epfd");
		return EXIT_FAILURE;
	}

	// 3) wait for events
	struct epoll_event *events;
	events = malloc(sizeof(struct epoll_event) * MAX_EVENTS);
	if (!events) {
		perror("malloc events");
		return EXIT_FAILURE;
	}

	printf("Type something and do Ctrl+D\n");

	int nr_events = epoll_wait(epfd, events, MAX_EVENTS, -1);
	if (nr_events == -1) {
		perror("Wait events");
		free(events);
		return EXIT_FAILURE;
	}
	
	int i;
	for (i = 0; i < nr_events; i++) {
		printf("[fd: %d] Spot event: %lu\n", events[i].data.fd, (unsigned long)events[i].events);
	}

	free(events);

	// close epfd
	if (close(epfd)) {
		perror("Close epfd");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
