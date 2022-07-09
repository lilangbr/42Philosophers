/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:26:40 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/09 19:58:33 by ebresser         ###   ########.fr       */
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
		status->philos[i].meals_eaten = 0;
		status->philos[i].is_dead = &status->is_dead;		
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
static void	init_mutex_forks(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->args->number_philos)
	{
		pthread_mutex_init(&status->forks[i], NULL);
		i++;
	}
}

void	init_status(t_status *status, t_args *args)
{
	pthread_t	thread[200];

	status->args = args;
	status->simul_start = get_time();//
	status->time_of_death = 0;
	status->is_dead = FALSE;	
	pthread_mutex_init(&status->waiter, NULL);
	pthread_mutex_init(&status->printer, NULL);
	init_mutex_forks(status);
	set_philos(status); 
	start_simulation(status, thread); 
	//join_threads(status, thread);	 
}