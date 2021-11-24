#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int find_file(const char *path, const char *filename) {
	int rslt = -1;

	// open target dir
	DIR *dir = opendir(path);
	if(!dir) {
		perror("opendir");
		return rslt;
	}

	//printf("[DEBUG] %s opened.\n", path);

	struct dirent *ent;
	errno = 0;
	while((ent = readdir(dir))){
		//printf("[DEBUG] %s\n", ent->d_name);
		if(!strcmp(ent->d_name, filename)) {
			//printf("[DEBUG] Find %s!\n", ent->d_name);
			rslt = 0;
			break;
		}
	}

	if(!ent && errno)
		perror("readdir");

	if(closedir(dir))
		perror("closedir");

	return rslt;
}

int main() {
	if(!find_file("/tmp", "helloworld")){
		printf("File found!\n");
	}else{
		printf("File not found!\n");
	}

	return EXIT_SUCCESS;
}
