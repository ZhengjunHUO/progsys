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
	if(stat(argv[1], &st)) {
		perror("stat");
		return EXIT_FAILURE;
	}
	
	printf("Info about %s:\ninode: %ld\nhardlink(s): %ld\nmode: %o\nsize: %ld bytes\nblocksize: %ld\nblocknb: %ld\n", argv[1], st.st_ino, st.st_nlink, st.st_mode&0777, st.st_size, st.st_blksize, st.st_blocks);

	return EXIT_SUCCESS;	
}
