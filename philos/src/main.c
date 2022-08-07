/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:38:09 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/10 20:27:32 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_status	status;

	if (input_errors(argc, argv) == TRUE)
		return (1);
	set_input(argc, argv, &status);
	if (create_philos(&status) == FALSE)
		return (1);
	if (create_forks(&status) == FALSE)
		return (1);
	if (create_threads(&status) == FALSE)
		return (1);
	if (destroy_mutex(&status) == FALSE)
		return (1);
	free(status.philo);
	free(status.forks);
	return (0);
}
