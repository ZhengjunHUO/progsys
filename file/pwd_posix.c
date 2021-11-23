#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main() {
	char buf[255];
	if(!getcwd(buf, 255)){
		perror("getcwd");
		return EXIT_FAILURE;
	}

	printf("Current working directory: %s\n", buf);
	return EXIT_SUCCESS;
}
