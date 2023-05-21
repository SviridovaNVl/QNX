#include <stdio.h>
#include <time.h>
#include <sync.h>
#include <sys/neutrino.h>

barrier_t bar;

void *thread_1(void *not_used)
{
	time_t now;
	char buf[27];
	time(&now);
	
	printf("Thread 1, start time: %s \n", ctime_r(&now, buf));
	sleep(5);
	barrier_wait(&bar);
	printf("Nina \n");
}

void *thread_2(void *not_used)
{
	time_t now;
	char buf[27];
	time(&now);
	
	printf("Thread 2, start time: %s \n", ctime_r(&now, buf));
	sleep(10);
	barrier_wait(&bar);
	printf("Sviridova I992 \n");
}

void main(void)
{
	time_t now;
	char buf[27];
	
	barrier_init(&bar, NULL, 3);
	printf("Start \n");
	pthread_create(NULL, NULL, thread_1, NULL);
	pthread_create(NULL, NULL, thread_2, NULL);
	
	time(&now);
	printf("From main(): waiting for the barrier, cur time: %s \n", ctime_r(&now, buf));
	sleep(5);
	barrier_wait(&bar);
	
	time(&now);
	printf("Threads terminated at: %s \n", ctime_r(&now, buf));
	printf("Everything working fine");
}
