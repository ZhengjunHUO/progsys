#include <alloca.h>
#include <fcntl.h>
#include <string.h>

#define ETC_CONFIG_DIR "/etc/"

int open_etc_config(const char *filename, int flags, mode_t mode) {
	const char *etc = ETC_CONFIG_DIR;

	// allocate memory on the stack
	char * pathtofile = alloca(strlen(etc) + strlen(filename) + 1);
	strcpy(pathtofile, etc);
	strcat(pathtofile, filename);

	return open(pathtofile, flags, mode);
}
