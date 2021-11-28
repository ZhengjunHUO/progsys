#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	printf("The current break point is at: %p\n", sbrk(0));
}
