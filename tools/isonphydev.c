#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sysmacros.h>

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
	
	//printf("st_dev: %ld\n", st.st_dev);
	//printf("%d\n", gnu_dev_major(st.st_dev));
	if(!gnu_dev_major(st.st_dev)) {
		printf("File [%s] is NOT on physical device.\n", argv[1]);
	}else{
		printf("File [%s] is on physical device.\n", argv[1]);
	}

	return EXIT_SUCCESS;	
}
