#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct rlimit rl, rl2;

	if(getrlimit(RLIMIT_NOFILE, &rl)) {
		perror("getrlimit");
		return EXIT_FAILURE;
	}

	printf("[Inherited limits] Soft: %ld; Hard: %ld\n", rl.rlim_cur, rl.rlim_max);

	rl.rlim_cur = rl.rlim_cur * 2;
	rl.rlim_max = rl.rlim_max * 2;
	//rl.rlim_max = RLIM_INFINITY;
	if(setrlimit(RLIMIT_NOFILE, &rl)) {
		perror("setrlimit");
		return EXIT_FAILURE;
	}

	if(getrlimit(RLIMIT_NOFILE, &rl2)) {
		perror("getrlimit");
		return EXIT_FAILURE;
	}

	printf("[New limits applied] Soft: %ld; Hard: %ld\n", rl2.rlim_cur, rl2.rlim_max);
}
