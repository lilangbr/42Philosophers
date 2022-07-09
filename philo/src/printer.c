/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:39:49 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/09 19:35:01 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	select_color(char *color, int type)
{
	if (type == THINKING)
		ft_strlcpy(color, BOLD_PURPLE, 10);
	else if (type == SLEEPING)
		ft_strlcpy(color, BOLD_CYAN, 10);
	else if (type == EATING)
		ft_strlcpy(color, BOLD_YELLOW, 10);
	else if (type == PICK_LEFT_FORK)
		ft_strlcpy(color, YELLOW, 10);
	else if (type == PICK_RIGHT_FORK)
		ft_strlcpy(color, YELLOW, 10);
	else if (type == DROP_LEFT_FORK)
		ft_strlcpy(color, GREEN, 10);
	else if (type == DROP_RIGHT_FORK)
		ft_strlcpy(color, GREEN, 10);
	else if (type == SATIATED)
		ft_strlcpy(color, BOLD_ORANGE, 10);
	else if (type == DEAD)
		ft_strlcpy(color, BOLD_RED, 10);
}

void	output(long long int timestamp, int id, int type, int meals)
{
	char	color[10];

	select_color(color, type);
	printf("%s", color);
	printf("% 10lld | ", timestamp);
	if (type == THINKING)
		printf("Philo %d is thinking. !!!!!!!!.\n", id);
	else if (type == SLEEPING)
		printf("Philo %d is sleeping. ZzZzZzZz.\n", id);
	else if (type == EATING)
		printf("Philo %d is eating! Yum!\n", id);
	else if (type == PICK_LEFT_FORK)
		printf("Philo %d took his left  fork.\n", id);
	else if (type == PICK_RIGHT_FORK)
		printf("Philo %d took his right fork.\n", id);
	else if (type == DROP_LEFT_FORK)
		printf("Philo %d dropped his left  fork.\n", id);
	else if (type == DROP_RIGHT_FORK)
		printf("Philo %d dropped his right fork.\n", id);
	else if (type == SATIATED)
		printf("Philo %d ate %d meals and is now satiated!\n", id, meals);
	else if (type == DEAD)
		printf("Philo %d has starved to death\n", id);
	printf("%s", RESET_COLOR);
}

