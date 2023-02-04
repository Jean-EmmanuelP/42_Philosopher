#include <sys/time.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Code a mesurer ici
    int i;
    for (i = 0; i < 100; i++)
        i++;
    printf("value de i : %d\n", i);
    usleep(1000);

    gettimeofday(&end, NULL);

    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000
    + (end.tv_usec - start.tv_usec);
    printf("Le temps ecoule est de %d microsecondes\n", elapsed_time);

    return (0);
}