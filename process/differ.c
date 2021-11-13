#include <stdlib.h>
#include <stdio.h>

void def1() {
	printf("I'm the 1st func registered to atexit()\n");
}

void def2() {
	printf("I'm the 2nd func registered to atexit()\n");
}

int main() {
	if(atexit(def1))
		fprintf(stderr, "Register def1 to atexit() failed\n");

	if(atexit(def2))
		fprintf(stderr, "Register def2 to atexit() failed\n");

	printf("Before return ...\n");
	return EXIT_SUCCESS;
}
