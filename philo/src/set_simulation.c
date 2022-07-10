/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:26:40 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 13:01:19 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	set_philos(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->args->number_philos)
	{
		status->philos[i].id = i + 1;
		status->philos[i].left_hand = 0;
		status->philos[i].right_hand = 0;
		status->philos[i].meals_eaten = 0;
		status->philos[i].is_dead = &status->is_dead;
		status->philos[i].dead_index = &status->dead_index;
		status->philos[i].time_of_death = &status->time_of_death;
		status->philos[i].last_meal = 0;
		status->philos[i].left_fork = &status->forks[i];
		status->philos[i].right_fork = &status->forks[(i + 1)
			% status->args->number_philos];
		status->philos[i].time_to_sleep = status->args->time_to_sleep;
		status->philos[i].time_to_eat = status->args->time_to_eat;
		status->philos[i].time_to_die = status->args->time_to_die;
		status->philos[i].number_meals = &status->args->number_meals;
		status->philos[i].simul_start = status->simul_start;
		status->philos[i].waiter = &status->waiter;
		status->philos[i].printer = &status->printer;
		i++;
	}
}
static int	init_mutex_forks(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->args->number_philos)
	{
		if (pthread_mutex_init(&status->forks[i], NULL) != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	init_status(t_status *status, t_args *args)
{
	pthread_t	thread[200];

	status->args = args;
	status->simul_start = now_ms();
	status->time_of_death = 0;
	status->is_dead = FALSE;
	status->dead_index = 0;
	if (pthread_mutex_init(&status->waiter, NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&status->printer, NULL) != 0)
		return (FALSE);
	if (init_mutex_forks(status) == FALSE)
		return (FALSE);
	set_philos(status); 
	start_simulation(status, thread);
	return (TRUE);	 
}