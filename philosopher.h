/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:04:39 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:04:40 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

# include <sys/time.h>
# include <limits.h>

# include "./srcs/ft_malloc/ft_malloc.h"

# define VALID 1
# define INVALID 0
# define TRUE 1
# define FALSE 0

//printf_mutex
# define MESSAGE_GET_FORK "has taken a fork"
# define MESSAGE_EAT "is eating"
# define MESSAGE_SLEEP "is sleeping"
# define MESSAGE_THINK "is thinking"
# define MESSAGE_DIE "died"

# define DEFAULT_ARGS_NUM 5

typedef struct s_mutexes
{
	pthread_mutex_t	print;
	pthread_mutex_t	fork_id0;
}	t_mutexes;

typedef struct s_accurate_time
{
	long long int	ideal_time_usec;
	long long int	actual_time_usec;
	long long int	dt;
}	t_accurate_time;

typedef struct s_philosopher
{
	int				time_to_die_usec;
	int				time_to_eat_usec;
	int				time_to_sleep_usec;
	long long int	time_last_eat_usec;
	int				time_die;
	int				num_eat_left;
	int				id;
	pthread_t		thread;
	long long int	start_time_usec;
	long long int	*start_time_addr;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_mutexes		*mutexes;
	int				num_eaten;
	volatile int	*is_simulation_started;
	volatile int	*is_simulation_finished;
	t_accurate_time	accurate_time;
	int				num_philosopher;
}	t_philosopher;

typedef struct s_philosopher_data
{
	int				num_philosophers;
	int				time_to_die;
	int				time_to_eat_usec;
	int				time_to_sleep_usec;
	int				num_eat_time;
	long long int	start_time_usec;
	t_mutexes		mutexes;
	int				is_simulation_started;
	int				is_simutation_finished;
}	t_philosopher_data;

typedef enum e_err
{
	NO_ERR,
	MALLOC_FAIL,
	INPUT_NULL_POINTER,
	OVER_FLOW,
	NO_DIGITS,
	INVALID_ARG_NUM,
	INVALID_ARG_VALUE,
	ANOTHER_ERR,
	SENTINEL,
}	t_err;

typedef struct s_all
{
	t_err				err;
	t_philosopher_data	philosopher_data;
	pthread_mutex_t		*fork;
	t_philosopher		*philosopher_arry;
	pthread_t			monitoring_thread;
}	t_all;

//main
void			ft_finalize(t_all *all);

//check
int				is_valid_args(int argc, char **argv, t_err *err);

//set
t_err			set_all(t_all *all, char **argv);
void			set_philosopher_data(t_philosopher_data *data, \
	char **argv, t_err *err);
pthread_mutex_t	*make_fork(int num_philosophers, t_err *err);
t_philosopher	*make_philosopher_arry(int num_philosophers, \
	t_err *err);
void			set_philosopher_arry(t_philosopher *philosopher_arry, \
	t_philosopher_data *data, pthread_mutex_t *fork);

//thread
t_err			start_threads_odd_num(t_all *all);
t_err			start_threads_even_num(t_all *all);
void			*monitoring_threads(void *p);

//action
void			philosopher_take_fork_odd(t_philosopher *philosopher);
void			philosopher_eat_odd(t_philosopher *philosopher);
void			philosopher_sleep_odd(t_philosopher *philosopher);
void			philosopher_think_odd(t_philosopher *philosopher);

void			philosopher_take_fork_even(t_philosopher *philosopher);
void			philosopher_eat_even(t_philosopher *philosopher);
void			philosopher_sleep_even(t_philosopher *philosopher);
void			philosopher_think_even(t_philosopher *philosopher);

//error
int				ft_error(t_all *all);

//utils
int				ft_atoi(char *s, t_err *err);
void			ft_bzero(void *p, size_t size);
long long int	ft_get_time_msec(void);
long long int	ft_get_time_usec(void);
void			print_log_mutex(t_philosopher *philosopher, char *s);
void			ft_usleep(long long int sleep_time);
void			update_accurate_time(t_accurate_time *accurate_time, \
	int time_to_action);

#endif
