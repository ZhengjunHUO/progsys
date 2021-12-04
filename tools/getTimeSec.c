#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	time_t t;

	printf("Current time since epoch is: %ld\n", time(&t));
	printf("Time saved in time_t with the previous call: %ld\n", t);
	return EXIT_SUCCESS;
}
