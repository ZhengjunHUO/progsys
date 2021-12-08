#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	timer_t t;
	struct sigevent sev;

	sev.sigev_notify = SIGEV_SIGNAL;
	sev.sigev_signo = SIGUSR2;
	sev.sigev_value.sival_int = 666;
	sev.sigev_value.sival_ptr = &t;

	if (timer_create(CLOCK_REALTIME, &sev, &t)) {
		perror("timer_create");
		return EXIT_FAILURE;
	}

	printf("Timer created!\n");

	return EXIT_SUCCESS;
}
