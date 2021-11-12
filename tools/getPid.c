#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void get_pid() {
	printf("My pid is: %d\n", getpid());
	printf("My ppid is: %d\n", getppid());
}

int main() {
	get_pid();
	return EXIT_SUCCESS;
}
