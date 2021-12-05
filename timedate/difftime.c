#include <time.h>
#include <stdio.h>

int main() {
	printf("%.0lf seconds between the today and an important day.\n", difftime(time(NULL), 648604800));
	return 0;
}
