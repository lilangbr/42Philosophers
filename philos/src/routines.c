/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:51:29 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:37:25 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	t_status	*status;
	int			i;

	status = (t_status *)args;
	i = status->n_thread;
	if (status->input.num_of_times_eat > 0)
	{
		while (status->input.num_of_times_eat > \
			status->philo[i].num_of_times_ate \
			&& status->philo_dead == FALSE)
			routine_execute(status, i);
	}
	else
	{
		while (status->philo_dead == FALSE)
		{
			if (routine_execute(status, i) == FALSE)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_status *status, int i)
{
	if (philo_eat(status, i) == FALSE)
		return (FALSE);
	if (status->input.num_of_times_eat != status->philo[i].num_of_times_ate)
	{
		if (philo_sleep(status, i) == FALSE)
			return (FALSE);
		if (philo_think(status, i) == FALSE)
			return (FALSE);
	}
	else
		philo_print(status, status->philo[i].id, BOLD_ORANGE, SATIATED);
	return (TRUE);
}

void	*checker(void *args)
{
	t_status	*status;
	int			i;

	status = (t_status *)args;
	i = 0;
	if (status->input.num_of_times_eat > 0)
	{
		while (status->input.num_of_times_eat > \
			status->philo[i].num_of_times_ate \
			&& status->philo_dead == FALSE)
		{
			if (philo_is_dead(status, &i) == TRUE)
				break ;
		}
	}
	else
	{
		while (status->philo_dead == FALSE)
		{
			if (philo_is_dead(status, &i) == TRUE)
				break ;
		}
	}
	return (NULL);
}

int	philo_print(t_status *status, int id, char *color, char *action)
{
	long long	now;

	now = duration_ms(status->t0);
	if (status->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&status->printer);
	if (status->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&status->printer);
		return (FALSE);
	}
	else
		printf("%s%-10lld %-3d %-30s%s\n", color, now, id, action, RESET);
	pthread_mutex_unlock(&status->printer);
	return (TRUE);
}
