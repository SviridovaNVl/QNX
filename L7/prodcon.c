#include <stdio.h>
#include <pthread.h>

int data_ready = 0;
int inf = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *consumer(void *not_used)
{
	printf("eto potrebitel \n");
	
	while(1)
	{
		pthread_mutex_lock(&mutex);
		printf("W1 \n");
		while (!data_ready)
		{
			printf("W2 \n");
			pthread_cond_wait(&cond, &mutex);
			printf("W3 \n");
		}
	printf("dannie ot proizvod = %d \n", inf);
	data_ready = 0;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);
	}
}

void *producer(void *not_used)
{
	printf("Eto proizvoditel \n") ;
	
	while(1)
	{
		sleep(2);
		printf("proizvoditel polychil daniie ot h/w = %d \n", inf);
		pthread_mutex_lock(&mutex);
		printf("Wpl \n");
		while(data_ready)
		{
			printf("Wp2 \n");
			pthread_cond_wait(&cond, &mutex);
		}
		data_ready = 1;
		inf++;
		printf("Wp3 \n");
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}

int main(void)
{
	printf("Start. Sviridova Nina I992\n");
	pthread_create(NULL,NULL, consumer, NULL);
	pthread_create(NULL,NULL, producer, NULL);
	sleep(10);
	return 0;
}
