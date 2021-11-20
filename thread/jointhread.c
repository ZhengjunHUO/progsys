#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

void * thread_run(void *text) {
	pid_t * tid = malloc(sizeof(pid_t));
	*tid = syscall(SYS_gettid);

	int i;
	for(i=0; i<3; i++) {
		printf("%s\n", (const char*) text);
	}

	pthread_exit((void *)tid);
}

int main() {
	printf("Process run with PID: %d\n", getpid());
	pthread_t t1, t2;
	void *ret1, *ret2;
	const char *text1 = "Thread 1 is speaking";
	const char *text2 = "Thread 2 is speaking";

	pthread_create(&t1, NULL, thread_run, (void *) text1);
	pthread_create(&t2, NULL, thread_run, (void *) text2);

	pthread_join(t1, &ret1);
	pthread_join(t2, &ret2);

	pid_t tid = syscall(SYS_gettid);
	printf("Master thread[%d]: thread1[%d] joined!\n", tid, *(pid_t *)ret1);
	printf("Master thread[%d]: thread2[%d] joined!\n", tid, *(pid_t *)ret2);
	printf("Master thread[%d]: All threads are joined! Quit.\n", tid);
	return EXIT_SUCCESS;
}
