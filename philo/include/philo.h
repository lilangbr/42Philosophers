/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:58:57 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/04 22:37:48 by ebresser         ###   ########.fr       */
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
    pthread_mutex_t *mutex_r_fork;
    pthread_mutex_t *mutex_l_fork;
}				t_philo;

typedef struct	s_control
{
	t_philo			*philo;
	pthread_mutex_t *forks;
	pthread_t		ctrl;
}				t_control;

#endif