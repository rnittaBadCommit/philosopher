#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

#include <sys/time.h>
# include <limits.h>

# include "./srcs/ft_malloc/ft_malloc.h"

# define VALID 1
# define INVALID 0
# define TRUE 1
# define FALSE 0

# define DEFAULT_ARGS_NUM 5

typedef struct s_philosopher
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_last_eat;
	int	time_die;
	int	num_eat_left;
	int	id;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t *fork_right;
}	t_philosopher;

typedef struct s_philosopher_data
{
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	is_additional_args;
	int	start_time;
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
	t_philosopher		*philosopher_arry;
	t_philosopher_data	philosopher_data;
}	t_all;

//main
void	ft_finalize(t_all *all);

//check
int		is_valid_args(int argc, char **argv, t_err *err);

//set
t_err	set_all(t_all *all, char **argv);
t_err	set_philosophers(t_all *all, char **argv);

//process
t_err	main_process(t_all *all);

//error
int		ft_error(t_all *all);

//utils
int		ft_atoi(char *s, t_err *err);
void	ft_bzero(void *p, size_t size);
int		ft_get_time_sec();

#endif
