#include <sys/select.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	struct timespec ts = {
		.tv_sec = 10,
		.tv_nsec = 0
	};
	
	int res = pselect(STDIN_FILENO+1, &readfds, NULL, NULL, &ts, NULL);
	if (res == -1) {
		perror("Call pselect failed");
		return EXIT_FAILURE;
	}
	if (res == 0) {
		printf("Nothing's ready, time out!\n");
		return EXIT_SUCCESS;
	}

	if (FD_ISSET(STDIN_FILENO, &readfds)) {
		char buf[1024];
		ssize_t nr = read(STDIN_FILENO, buf, 1024);
		if (nr == -1) {
			perror("Read from stdin");
			return EXIT_FAILURE;
		}

		if (nr) {
			buf[nr] = '\0';
			printf("Read from stdin: %s\n", buf);
		}

		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}
