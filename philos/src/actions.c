/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:59:27 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 19:15:17 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_status *status, int i)
{
	if (pthread_mutex_lock(&status->forks[status->philo[i].left_fork]) != 0)
		return (FALSE);
	if (philo_print(status, status->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&status->forks[status->philo[i].right_fork]) != 0)
		return (FALSE);
	if (philo_print(status, status->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (philo_print(status, status->philo[i].id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	status->philo[i].last_meal = now_ms();
	exec_action(status->input.time_to_eat);
	drop_forks(status, i);
	return (TRUE);
}

int	philo_sleep(t_status *status, int i)
{
	if (philo_print(status, status->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	exec_action(status->input.time_to_sleep);
	return (TRUE);
}

int	philo_think(t_status *status, int i)
{
	if (philo_print(status, status->philo[i].id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	philo_is_dead(t_status *status, int *i)
{
	int	time;

	if (*i == status->input.num_philo)
		*i = 0;
	time = delta_time(status->philo[*i].last_meal);
	if (time > status->input.time_to_die)
	{
		philo_print(status, status->philo[*i].id, PINK, DIED);
		status->philo_dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}

int	drop_forks(t_status *status, int i)
{
	if (pthread_mutex_unlock(&status->forks[status->philo[i].left_fork]))
		return (FALSE);
	if (pthread_mutex_unlock(&status->forks[status->philo[i].right_fork]))
		return (FALSE);
	status->philo[i].num_of_times_ate++;
	return (TRUE);
}
