#include <pthread.h>

struct Compte {
	char titre[30];
	int solde;
	pthread_mutex_t lock;
};

extern int encaisser(struct Compte *account, int somme);
extern void distribute(int somme);
