#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void *routine(void *arg) {
	pthread_mutex_t *mutex = (pthread_mutex_t *)arg;
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(mutex);
		mails++;
		pthread_mutex_unlock(mutex);
	}
}

int main(int ac, char **av)
{
	pthread_t th[8];
	int i;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 8; i++)
	{
		if (pthread_create(th + i, NULL, &routine, &mutex))
		{
			perror("Failed to create thread");
			return 1;
		}
		printf("Thread %d has started\n", i);
		if (pthread_join(th[i], NULL))
			return 5;
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails : %d\n", mails);
}
