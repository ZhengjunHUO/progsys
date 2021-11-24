#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	// get origin dir's fd
	int fd = open(".", O_RDONLY);
	if(fd == -1){
		perror("open");
		return EXIT_FAILURE;
	}

	// do a "cd" to another dir
	if(chdir("/tmp")){
		perror("chdir");
		return EXIT_FAILURE;
	}

	char *wd = get_current_dir_name();
	if(!wd){
		perror("get_current_dir_name");
		return EXIT_FAILURE;
	}

	printf("Chdir to: %s\n", wd);

	// do a "cd -" to go back
	if(fchdir(fd)) {
		perror("fchdir");
		return EXIT_FAILURE;
	}

	wd = getcwd(NULL, 0);
	if(!wd){
		perror("getcwd");
		return EXIT_FAILURE;
	}
	printf("Going back to: %s\n", wd);

	free(wd);

	if(close(fd)) {
		perror("close");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
