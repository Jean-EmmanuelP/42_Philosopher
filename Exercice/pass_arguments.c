#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void *routine(void *args)
{
    int index =*(int *)args;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += primes[index + i];
    }
    *(int *)args = sum;
    return args;
}

int main(int ac, char **av)
{
    pthread_t th[2];
    int i;
    for (i = 0; i < 2; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a))
            perror("Failed to create thread");
    }
    int globalSum = 0;
    for (i = 0; i < 2; i++)
    {
        void *r;
        if (pthread_join(th[i], &r))
            perror("Failed to join thread");
        globalSum += *(int *)r;
        free(r);
    }
    printf("Global sum: %d\n", globalSum);
    return 0;
}