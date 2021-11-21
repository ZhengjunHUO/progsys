#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

#include "mutex.h"

struct Compte account = {"huo", 1000, PTHREAD_MUTEX_INITIALIZER};

void * thread_run(void *somme) {
	pid_t * tid = malloc(sizeof(pid_t));
	*tid = syscall(SYS_gettid);

	printf("Thread[%d]: ", *tid);
	encaisser(&account, *((int *)somme));

	pthread_exit((void *)tid);
}

void distribute(int somme) {
	printf("Get $%d!\n", somme);
}

int encaisser(struct Compte *account, int somme) {
	pthread_mutex_lock(&(account->lock));
	const int solde = account->solde;
	if(solde < somme) {
		printf("Overdraft is not allowed!\n");
		pthread_mutex_unlock(&(account->lock));
		return -1;
	}

	account->solde = solde - somme;
	pthread_mutex_unlock(&(account->lock));

	distribute(somme);
	return 0;
}

int main() {
	printf("The solde was $%d.\n", (&account)->solde);

	pthread_t t1, t2;
	int somme1=300, somme2=900;
	pthread_create(&t1, NULL, thread_run, (void *) &somme1);
	pthread_create(&t2, NULL, thread_run, (void *) &somme2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("The solde is $%d.\n", (&account)->solde);
	return EXIT_SUCCESS;	
}
