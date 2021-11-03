#include <stdio.h>
#include <stdlib.h>

int main() {
	struct tcpserver {
		char			servername[50];
		char			ipaddr[20];
		unsigned int	port;
	} zjunx, zjchat = { "ChatApp", "1.2.3.4", 8080};

	// write struct to file
	FILE *out = fopen("info", "w");
	if(!out) {
		perror("Open file to write");
		return EXIT_FAILURE;
	}

	size_t n = fwrite(&zjchat, sizeof(struct tcpserver), 1, out);
	if ( n != 1 ) {
		perror("fwrite to file");
		return EXIT_FAILURE;
	}

	if (fclose(out)) {
		perror("fclose out");
		return EXIT_FAILURE;
	}

	// restore struct from file
	FILE *in = fopen("info", "r");
	if(!in) {
		perror("Open file to read");
		return EXIT_FAILURE;
	}

	n = fread(&zjunx, sizeof(struct tcpserver), 1, in);
	if ( n != 1 ) {
		perror("fread from file");
		return EXIT_FAILURE;
	}

	if (fclose(in)) {
		perror("fclose in");
		return EXIT_FAILURE;
	}

	printf ("ServerName: %s\nIP Address: %s\nListenPort: %u\n", zjunx.servername, zjunx.ipaddr, zjunx.port);

	return EXIT_SUCCESS;
}
