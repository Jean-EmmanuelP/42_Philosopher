#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *args)
{
    int index =*(int *)arg;
    printf("%d", primes[index]);
}

int main(int ac, char **av)
{
    pthread_t th[10];
    for (int i = 0; i < 10; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, &i))
            perror("Failed to create thread");
    }
    for (int i = 0l i < 10; i++)
    {
        if (pthread_join(th[i], NULL))
            perror("Failed to join thread");
    }
    return 0;
}