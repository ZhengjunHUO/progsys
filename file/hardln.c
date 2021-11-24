#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	if(link("/tmp/helloworld", "/tmp/hard")){
		perror("link");
		return EXIT_FAILURE;
	}
	
	printf("Hard link created!\n");	
	return EXIT_FAILURE;
}
