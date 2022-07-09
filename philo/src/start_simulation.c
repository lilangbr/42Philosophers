/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:26:40 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/09 19:03:51 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	end_simulation(t_status *status, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < status->args->number_philos)
	{
		pthread_join(thread[i], NULL);
		pthread_mutex_destroy(&status->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&status->printer);
	pthread_mutex_destroy(&status->waiter);
}

int	start_simulation(t_status *status, pthread_t *thread)
{
	int		i;
	void	*current_philo;

	i = 0;
	while (i < status->args->number_philos)
	{
		current_philo = (void *)(&status->philos[i]);
		if (pthread_create(&thread[i], NULL, &philo_routine, current_philo) != 0)
			return (1);
		i++;
	}
	end_simulation(status, thread);	
	return (0);
}


