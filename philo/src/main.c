/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:34:10 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 13:42:06 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	get_input(char **argv, t_args *args)
{
	args->number_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->number_meals = ft_atoi(argv[5]);
	else
		args->number_meals = 0;
}

int main(int argc, char *argv[])
{
	t_args	args;
	t_status	status;
	pthread_t	thread[200];

	if (input_errors(argc, argv) == TRUE)
		return (1);
	get_input(argv, &args);
	if (init_status(&status, &args) == FALSE)
		return (1);
	if (start_simulation(&status, thread) == FALSE)
		return (1);
	if (status.is_dead)
		output(status.time_of_death, status.dead_index, DEAD, 0);	
    return (0);
}