/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 22:58:57 by ebresser          #+#    #+#             */
/*   Updated: 2022/07/09 20:00:08 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>

/*
** Standard macros redefined because the norme is a picky fucker.
*/

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define LONG_MAX 9223372036854775807
# define TRUE 1
# define FALSE 0

/*
** Error return macros.
*/

# define FEW_ARGS "ERROR: One or more arguments missing."
# define MANY_ARGS "ERROR: There are too many arguments."
# define INPUT_TOO_HIGH "ERROR: Input is above the int limit"
# define INPUT_TOO_LOW "ERROR: Input is below 1."
# define NOT_DIGIT "ERROR: Input should be an integer."
# define MANY_PHILOS "We don't need that many Ṕhilosophers. Put some back."
# define ZERO_PHILOS "If no one is there to eat the spaghetti, does it exist?"

/*
** Output definitions.
*/

# define THINKING 0
# define SLEEPING 1
# define EATING 2
# define PICK_LEFT_FORK 3
# define PICK_RIGHT_FORK 4
# define DROP_LEFT_FORK 5
# define DROP_RIGHT_FORK 6
# define SATIATED 7
# define DEAD 8

/*
** Color definitions.
*/

# define BLACK "\033[0;30m"
# define BOLD_BLACK "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define WHITE "\033[0;37m"
# define BOLD_WHITE "\033[1;37m"
# define ORANGE	"\e[0;38;5;166m"
# define BOLD_ORANGE "\e[0;38;5;202m"
# define RESET_COLOR "\033[0m"

/*
** Program state & philosopher structs.
*/
typedef struct s_args
{
	int	number_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_meals;
}		t_args;

typedef struct s_philo
{
	int				id;	
	int				*is_dead;	
	long long int	*time_of_death;	
	int				meals_eaten;
	int				*number_meals;
	long long int	last_meal;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long int	simul_start;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*waiter;
	pthread_mutex_t	*printer;
}				t_philo;

typedef struct s_status
{
	t_args			*args;
	t_philo			philos[200]; //depois com var
	pthread_mutex_t	forks[200];
	pthread_mutex_t	waiter;
	pthread_mutex_t	printer;
	long long int	simul_start;
	int				is_dead;
	int				dead_index;
	long long int	time_of_death;	
}				t_status;



//actions.c
void	release_forks(t_philo *philo);
void	pick_up_forks(t_philo *philo);
int	thinking(t_philo *philo);
int	sleeping(t_philo *philo);
int	eating(t_philo *philo);
//check_input.c
int				input_errors(int argc, char **argv);
//printer.c
void	output(long long int timestamp, int id, int type, int meals);	
//set_simulation.c
void	init_status(t_status *status, t_args *args);
//start_simulation.c
int	start_simulation(t_status *status, pthread_t *thread);

//threads_routines.c
int	is_satiated(t_philo *philo);
void	*philo_routine(void *philo_pointer);
//time.c
__uint64_t	get_time(void);
long long int	duration(long long int simul_start);
void	wait_time_in_ms(long long int time);
//utils.c
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
long long int	ft_atoll(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif