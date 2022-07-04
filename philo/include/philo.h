/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:58:57 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/04 00:28:59 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define N_PHILO 8

typedef struct s_philo
{
    int id;
    int *r_fork;
    int *l_fork;
    // pthread_mutex_t **mutex_r_fork;
    // pthread_mutex_t **mutex_l_fork;
} t_philo;

#endif