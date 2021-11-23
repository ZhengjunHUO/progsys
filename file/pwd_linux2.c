#define _GNU_SOURCE
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 

int main() {
	char *buf = get_current_dir_name();
	if(!buf) {
		perror("get_current_dir_name");
		return EXIT_FAILURE;
	}

	printf("Current working directory: %s\n", buf);
	// need to free it manuelly
	free(buf);
	return EXIT_SUCCESS;
}
