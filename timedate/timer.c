#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void myhandler(int signo) {
	printf("Receive signal [%s]\n", sys_siglist[signo]);
}

int main() {
	// create a timer 
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

	// arm a timer
	struct itimerspec ts;
	ts.it_interval.tv_sec = 1;
	ts.it_interval.tv_nsec = 0;
	ts.it_value.tv_sec = 3;
	ts.it_value.tv_nsec = 0;

	if (timer_settime(t, 0, &ts, NULL)) {
		perror("timer_settime");
	}

	if (signal(SIGUSR2, myhandler) == SIG_ERR) {
		perror("signal");
	}

	pause();

	// Check alarm overrun
	int ret = timer_getoverrun(t);
	if (ret == -1) {
		perror("timer_getoverrun");
	}else if(ret == 0) {
		printf("No overrun happened!\n");
	}else{
		printf("Alarm overrun %d sec!\n", ret);
	}

	// remove a timer
	if (timer_delete(t)) {
		perror("timer_delete");
		return EXIT_FAILURE;
	}

	printf("Timer deleted!\n");

	return EXIT_SUCCESS;
}
