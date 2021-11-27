#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cat {
	char name[20];
	int  age;
};

int main() {
	struct cat *fufu, *fu;
	fufu = calloc(2, sizeof(struct cat));
	if(!fufu) {
		perror("calloc");
		return EXIT_FAILURE;
	}

	strcpy(fufu[0].name, "fufu");
	fufu[0].age = 5;
	strcpy(fufu[1].name, "lulu");
	fufu[1].age = 3;

	printf("Cat %s is online.\n", fufu[0].name);
	printf("Cat %s is online.\n", fufu[1].name);

	fu = realloc(fufu, sizeof(struct cat));
	if(!fu) {
		perror("realloc");
		free(fufu);
		return EXIT_FAILURE;
	}

	printf("Cat %s is alone.\n", fu[0].name);

	free(fu);
	return EXIT_SUCCESS;
}
