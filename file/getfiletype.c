#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: %s </PATH/TO/FILE>\n", argv[0]);
		return EXIT_FAILURE;
	}

	struct stat st;
	// use lstat to identify the symbolic link
	if(lstat(argv[1], &st)) {
		perror("stat");
		return EXIT_FAILURE;
	}
	
	printf("%s's mode is %o\n", argv[1], st.st_mode);
	printf("%s is ", argv[1]);
	switch(st.st_mode & S_IFMT) {
	case S_IFREG:
		printf("a regular file.\n");
		break;
	case S_IFDIR:
		printf("a directory.\n");
		break;
	case S_IFLNK:
		printf("a symbolic link.\n");
		break;
	case S_IFSOCK:
		printf("a socket.\n");
		break;
	case S_IFIFO:
		printf("a FIFO.\n");
		break;
	case S_IFBLK:
		printf("a block device node.\n");
		break;
	case S_IFCHR:
		printf("a character device node.\n");
		break;
	default:
		printf("a unknown file.\n");
		break;
	}

	return EXIT_SUCCESS;	
}
