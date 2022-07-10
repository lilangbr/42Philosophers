/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:26:40 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 16:28:25 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	end_simulation(t_status *status, pthread_t *thread, pthread_t *end)
{
	int	i;

	i = 0;
	while (i < status->args->number_philos)
	{
		if (pthread_join(thread[i], NULL) != 0)
			return (FALSE);
		
		i++;
	}
	if (pthread_join(*end, NULL) != 0)
			return (FALSE);
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
	pthread_t	end;

	i = 0;
	while (i < status->args->number_philos)
	{
		current_philo = (void *)(&status->philos[i]);
		if (pthread_create(&thread[i], NULL, &philo_routine, current_philo) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_create(&end, NULL, &waiter_routine, (void *)status) != 0)
		return (FALSE); //NOVO
	end_simulation(status, thread, &end);	
	return (TRUE);
}


