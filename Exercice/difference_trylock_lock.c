#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

void *routine(void *arg)
{
    if (pthread_mutex_trylock(arg) != 0)
    {
        printf("Didn't get lock\n");
        return ((void*)NULL);
    }
    printf("Got lock\n");
    sleep(1);
    pthread_mutex_unlock(arg);
}

int main(int ac, char **av)
{
    pthread_t th[4];
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 4; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, &mutex))
            perror("Error at creating thread");
    }
    for (int i = 0; i < 4; i++)
    {
        if (pthread_join(th[i], NULL))
            perror("Error at joining thread");
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}