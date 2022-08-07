/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:35:42 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:40:10 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_status *status)
{
	int	i;

	i = 0;
	status->philo_dead = FALSE;
	status->t0 = now_ms();
	if (pthread_mutex_init(&status->printer, NULL) != 0)
		return (FALSE);
	while (i < status->input.num_philo)
	{
		status->n_thread = i;
		if (pthread_create(&status->philo[i].thread,
				NULL, &routine, (void *) status) != 0)
			return (FALSE);
		i++;
		usleep(1000);
	}
	if (pthread_create(&status->adm, NULL, &checker, (void *) status) != 0)
		return (FALSE);
	if (join_threads(status) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	join_threads(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->input.num_philo)
	{
		if (pthread_join(status->philo[i].thread, NULL) != 0)
			return (FALSE);
		i++;
	}
	if (pthread_join(status->adm, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	destroy_mutex(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->input.num_philo)
	{
		pthread_mutex_destroy(&status->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&status->printer);
	return (TRUE);
}
