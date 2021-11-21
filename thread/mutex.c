#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include "mutex.h"

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
	struct Compte account = {"huo", 1000, PTHREAD_MUTEX_INITIALIZER};
	
	printf("The solde was $%d.\n", (&account)->solde);
	encaisser(&account, 600);
	printf("The solde is $%d.\n", (&account)->solde);
	return EXIT_SUCCESS;	
}
