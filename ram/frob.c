#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char *text = "keep it secret.";
	int len = strlen(text);
	printf("Original text: [%s] (len: %d)\n", text, len);

	char *secret = calloc(1, len+1);
	if(!secret) {
		perror("calloc");
		return EXIT_FAILURE;	
	}
	strcpy(secret, text);

	memfrob(secret, len);
	printf("Frobbed text : [%s] (len: %d)\n", secret, len);

	memfrob(secret, len);
	printf("Restored text: [%s] (len: %d)\n", secret, len);

	return EXIT_SUCCESS;
}
