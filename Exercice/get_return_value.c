/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_return_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperrama <jperrama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:41:48 by jperrama          #+#    #+#             */
/*   Updated: 2023/02/04 13:51:55 by jperrama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *roll_dice()
{
    int value = (rand() % 6) + 1;
    int *result = malloc(sizeof(int));
    *result = value;
    // printf("%d\n", value);
    printf("Thread result: %d\n", result);
    return (void*) result;
}

int main(int ac, char **av)
{
    int *res;
    srand(time(NULL));
    pthread_t th;
    if (pthread_create(&th, NULL, &roll_dice, NULL))
        return 1;
    if (pthread_join(th, (void **) &res))
        return 2;
    printf("Result: %d\n", *res);
    free(res);
    return 0;
}