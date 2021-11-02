#include <stdio.h>
#include <stdlib.h>

# define BUFFER_SIZE 1024

const char DELIM = ';';

int main() {
	FILE *stream = fopen("/tmp/target", "r");
	if (!stream) {
		perror("Open stream");
		return EXIT_FAILURE;
	}

	char buf[BUFFER_SIZE];
	char *p = buf;
	int c = 0, n = 0;

	while ( n++ < BUFFER_SIZE-1 && (c = fgetc(stream)) != EOF) {
		/* replace the delimiter by \n */	
		if (c == DELIM ) {
			*p++ = '\n';
		}else{
			*p++ = c;
		}
	}

	*p = '\0';
	printf("Read from stream:\n%s", buf);

	if (fclose(stream)) {
		perror("Close stream");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
