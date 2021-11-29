#include <alloca.h>
#include <fcntl.h>
#include <string.h>

#include <stdio.h>
#include <malloc.h>

#define ETC_CONFIG_DIR "/etc/"

// allocate memory on the stack using alloca
int open_etc_config(const char *filename, int flags, mode_t mode) {
	const char *etc = ETC_CONFIG_DIR;

	char * pathtofile = alloca(strlen(etc) + strlen(filename) + 1);
	strcpy(pathtofile, etc);
	strcat(pathtofile, filename);

	return open(pathtofile, flags, mode);
}

// allocate memory on the stack using VLA
int open_etc_config2(const char *filename, int flags, mode_t mode) {
	const char *etc = ETC_CONFIG_DIR;

	char pathtofile[strlen(etc) + strlen(filename) + 1];
	strcpy(pathtofile, etc);
	strcat(pathtofile, filename);

	return open(pathtofile, flags, mode);
}

// allocate memory on the heap using malloc
int open_etc_config3(const char *filename, int flags, mode_t mode) {
	const char *etc = ETC_CONFIG_DIR;

	char * pathtofile = malloc(strlen(etc) + strlen(filename) + 1);
	if (!pathtofile) {
		perror("malloc");
		return -1;
	}

	strcpy(pathtofile, etc);
	strcat(pathtofile, filename);

	int fd = open(pathtofile, flags, mode);
	free(pathtofile);

	return fd;
}
