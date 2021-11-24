#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	// save origin path
	char *wd_origin = getcwd(NULL, 0);
	if(!wd_origin){
		perror("getcwd");
		return EXIT_FAILURE;
	}

	printf("Origin working path: %s\n", wd_origin);

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
	if(chdir(wd_origin)) {
		perror("chdir");
		return EXIT_FAILURE;
	}

	wd = getcwd(NULL, 0);
	if(!wd){
		perror("getcwd");
		return EXIT_FAILURE;
	}
	printf("Going back to: %s\n", wd);

	free(wd_origin);
	free(wd);
	return EXIT_SUCCESS;
}
