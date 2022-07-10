/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:43:53 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 12:09:42 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	philo->left_hand = 0;
	if (*philo->is_dead == FALSE && is_satiated(philo) == FALSE)
	{
		pthread_mutex_lock(philo->printer);
		output(duration_ms(philo->simul_start), philo->id, DROP_LEFT_FORK, 0);
		pthread_mutex_unlock(philo->printer);
	}
	pthread_mutex_unlock(philo->right_fork);
	philo->right_hand = 0;
	if (*philo->is_dead == FALSE && is_satiated(philo) == FALSE)
	{
		pthread_mutex_lock(philo->printer);
		output(duration_ms(philo->simul_start), philo->id, DROP_RIGHT_FORK, 0);
		pthread_mutex_unlock(philo->printer);
	}
	philo->meals_eaten += 1;
}

void	pick_up_forks(t_philo *philo)
{
	
		pthread_mutex_lock(philo->left_fork);
		philo->left_hand = 1;
		if (*philo->is_dead == FALSE && is_satiated(philo) == FALSE)
		{
			pthread_mutex_lock(philo->printer);
			output(duration_ms(philo->simul_start), philo->id, PICK_LEFT_FORK, 0);
			pthread_mutex_unlock(philo->printer);
		}
		pthread_mutex_lock(philo->right_fork);
		philo->right_hand = 1;
		if (*philo->is_dead == FALSE && is_satiated(philo) == FALSE)
		{
			pthread_mutex_lock(philo->printer);
			output(duration_ms(philo->simul_start), philo->id, PICK_RIGHT_FORK, 0);
			pthread_mutex_unlock(philo->printer);
		}		
		philo->last_meal = duration_ms(philo->simul_start);	
}

int	thinking(t_philo *philo)
{
	if (*philo->is_dead == TRUE || is_satiated(philo) == TRUE)
		return (FALSE);
	else
	{
		pthread_mutex_lock(philo->printer);
		output(duration_ms(philo->simul_start), philo->id, THINKING, 0);
		pthread_mutex_unlock(philo->printer);
		return (TRUE);
	}
}

int	sleeping(t_philo *philo)
{
	if (*philo->is_dead == TRUE || is_satiated(philo) == TRUE)
		return (FALSE);
	else
	{
		pthread_mutex_lock(philo->printer);
		output(duration_ms(philo->simul_start), philo->id, SLEEPING, 0);
		pthread_mutex_unlock(philo->printer);
		wait_ms(philo->time_to_sleep);
		return (TRUE);
	}
}

int	eating(t_philo *philo)
{
	if (*philo->is_dead == TRUE || is_satiated(philo) == TRUE)
		return (FALSE);
	if ((duration_ms(philo->simul_start) - philo->last_meal)
		> philo->time_to_die && *philo->is_dead == FALSE)
		return (FALSE);
	pick_up_forks(philo);
	if (*philo->is_dead == FALSE && is_satiated(philo) == FALSE)
	{	
		pthread_mutex_lock(philo->printer);
		output(duration_ms(philo->simul_start), philo->id, EATING, 0);
		pthread_mutex_unlock(philo->printer);
	}
	wait_ms(philo->time_to_eat);
	release_forks(philo);
	return (TRUE);
}
