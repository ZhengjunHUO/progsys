#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * thread_run(void *text) {
	int i;
	for(i=0; i<3; i++) {
		printf("%s\n", (const char*) text);
	}
	return text;
}

int main() {
	pthread_t t1, t2;
	const char *text1 = "Thread 1 is speaking";
	const char *text2 = "Thread 2 is speaking";

	pthread_create(&t1, NULL, thread_run, (void *) text1);
	pthread_create(&t2, NULL, thread_run, (void *) text2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("All threads are joined! Quit.\n");
	return EXIT_SUCCESS;
}
