/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_vs_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:09:57 by jperrama          #+#    #+#             */
/*   Updated: 2023/02/04 12:33:35 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef P

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int ac, char **av)
{
    int x = 2;
    int pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
        x++;
    sleep(2);
    printf("Value of x : %d\n", x);
    printf("Process id %d\n", getpid());
    if (pid != 0)
        wait(NULL);
    return (0);
}

#endif

#ifdef T

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void *routine()
{
    x++;
    sleep(2);
    printf("Value of x : %d\n", x);
    printf("Process id %d\n", getpid());
}

void *routine2()
{
    sleep(2);
    printf("Value of x : %d\n", x);
}

int main(int ac, char **av)
{
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL))
        return (1);
    if (pthread_create(&t2, NULL, &routine2, NULL))
        return (2);
    if (pthread_join(t1, NULL))
        return (3);
    if (pthread_join(t2, NULL))
        return (4);
    return (0);
}

#endif 
