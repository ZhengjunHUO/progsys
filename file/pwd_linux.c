#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main() {
	char *buf = getcwd(NULL, 0);
	if(!buf) {
		perror("getcwd");
		return EXIT_FAILURE;
	}

	printf("Current working directory: %s\n", buf);
	// need to free it manuelly
	free(buf);
	return EXIT_SUCCESS;
}
