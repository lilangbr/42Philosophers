/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:33:58 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 12:15:33 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/philo.h"

int	is_satiated(t_philo *philo)
{
	if (*philo->number_meals > 0 && philo->meals_eaten == *philo->number_meals)
		return (TRUE);
	return (FALSE);
}

static void	satiation_sequence(t_philo *philo)
{
	pthread_mutex_lock(philo->printer);
	output(duration_ms(philo->simul_start), philo->id,
		SATIATED, philo->meals_eaten);
	pthread_mutex_unlock(philo->printer);
}

static void	death_sequence(t_philo *philo)
{
	*philo->is_dead = TRUE;
	*philo->time_of_death = duration_ms(philo->simul_start);
	*philo->dead_index = philo->id;//
}

static void	*waiter_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pointer;
	while (1)
	{
		if (*philo->is_dead == TRUE)
			return ((void *)1);
		if (is_satiated(philo) == TRUE)
		{
			satiation_sequence(philo);
			return ((void *)1);
		}
		if ((duration_ms(philo->simul_start) - philo->last_meal)
			> philo->time_to_die && *philo->is_dead == FALSE)
		{
			if (philo->left_hand == 1)
			{
				pthread_mutex_unlock(philo->left_fork);
			}				
			if (philo->right_hand == 1)
			{
				pthread_mutex_unlock(philo->right_fork);
			}				
			pthread_mutex_lock(philo->waiter);
			death_sequence(philo);
			pthread_mutex_unlock(philo->waiter);
			return ((void *)1);
		}
	}
}

void	*philo_routine(void *philo_pointer)
{
	t_philo		*philo;
	pthread_t	end;

	philo = (t_philo *)philo_pointer;
	if (pthread_create(&end, NULL, &waiter_routine, philo) != 0)
		return ((void *)1);
	pthread_detach(end);
	if (philo->id % 2 == 0)
		usleep(6000);
	while (eating(philo) && sleeping(philo) && thinking(philo))
		continue ;
	return (NULL);
}