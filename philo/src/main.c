/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:34:10 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/04 00:38:32 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char *argv[])
{
    char *s;
    argc = argc - 1;
    s = argv[0];
    int i;
    printf("Hello from %s!\n", s);
    //----------------------------------
    int fork[N_PHILO];
    t_philo philo[N_PHILO];
    // pthread_mutex_t mutex_fork[N_PHILO];

    // init struct
    i = 0;
    while (i < N_PHILO)
    {
        fork[i] = i + 1;
        philo[i].id = i + 1;
        if (i + 1 != 1)
        {
            philo[i].r_fork = fork + i - 1;
            philo[i].l_fork = fork + i;
        }
        else
        {
            philo[i].r_fork = fork + N_PHILO - 1;
            philo[i].l_fork = fork + i;
        }
        i++;
    }
    i = 0;
    while (i < N_PHILO)
    {
        printf("Philo %d:::::::::::\n", i + 1);
        printf("____id: %d:\n", philo[i].id);
        // printf("%d\n", *(fork + i));
        printf("r_fork: %d:\n", *(philo[i].r_fork));
        printf("l_fork: %d:\n", *(philo[i].l_fork));
        i++;
    }

    return (0);
}