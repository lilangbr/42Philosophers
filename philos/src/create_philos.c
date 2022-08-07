/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:17:03 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 19:22:52 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philos(t_status *status)
{
	int	i;
	int	j;

	status->philo = malloc(sizeof(t_philo) * (status->input.num_philo + 1));
	if (status->philo == NULL)
		return (FALSE);
	i = 0;
	j = 1;
	while (j < status->input.num_philo)
	{
		fill_philo_struct(status, i, j);
		i++;
		j++;
	}
	j = 0;
	fill_philo_struct(status, i, j);
	return (TRUE);
}

void	fill_philo_struct(t_status *status, int i, int j)
{
	status->philo[i].id = i + 1;
	status->philo[i].num_of_times_ate = 0;
	status->philo[i].last_meal = 0;
	status->philo[i].left_fork = i;
	status->philo[i].right_fork = j;
}
