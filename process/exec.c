#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char *const args[] = {"vi", "/tmp/txt", NULL};

	int ret = execv("/bin/vi", args);
	if (ret == -1) {
		perror("execv vi");
		return EXIT_FAILURE;
	}

	printf("this line won't be printed");
	return EXIT_SUCCESS;
}
