/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:26:40 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 13:14:27 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	end_simulation(t_status *status, pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < status->args->number_philos)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (FALSE);
		
		i++;
	}
	while (i < status->args->number_philos)
	{
		pthread_mutex_destroy(&status->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&status->printer);
	pthread_mutex_destroy(&status->waiter);
	return (TRUE);
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
			return (FALSE);
		i++;
	}
	end_simulation(status, thread);	
	return (TRUE);
}


