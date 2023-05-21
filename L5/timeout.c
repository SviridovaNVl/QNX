#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <time.h>
#include <sys/neutrino.h>

#define SEC 1000000000LL

void *thread_1(void *not_used)
{
	time_t now;
	char buf[30];
	time(&now);
	
	printf("This thread terminates in 15 secs. Student: Sviridova Nina I992 \n");
	printf("Time thread started: %s \n\n", ctime_r(&now, buf));
	sleep(15);
}

int main(void)
{
	uint64_t timeout;
	struct sigevent event;
	int rval;
	pthread_t thread_id;
	time_t now;
	char buf[30];
	
	printf("Prog timer \n");
	event.sigev_notify = SIGEV_UNBLOCK;
	pthread_create(&thread_id, NULL, thread_1, NULL);
	
	timeout = 10LL*SEC;
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	rval = pthread_join(thread_id, NULL);
	if (rval == ETIMEDOUT)
	{
		printf("10 secs timed out, thread %d isnt terminated !! \n" , thread_id);
		time(&now);
		printf("Current time: %s \n\n", ctime_r(&now, buf));
	}
	sleep(5);
	
	TimerTimeout(CLOCK_REALTIME, _NTO_TIMEOUT_JOIN, &event, &timeout, NULL);
	rval = pthread_join(thread_id, NULL);
	if (rval == ETIMEDOUT)
	{
		printf("Thread %d > 25 sec !! ", thread_id);
		time(&now);
		printf("Current time: %s \n\n", ctime_r(&now, buf));
	}
	else
	{
		printf("Thread %d has correctly terminated \n", thread_id);
		time(&now);
		printf("Current time: %s \n\n", ctime_r(&now, buf));
	}
	return (1);
}