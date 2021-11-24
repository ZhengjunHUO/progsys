#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	if(symlink("/tmp/helloworld", "/tmp/soft")){
		perror("symlink");
		return EXIT_FAILURE;
	}
	
	printf("Soft link created!\n");	
	return EXIT_FAILURE;
}
