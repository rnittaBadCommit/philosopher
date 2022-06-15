#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

# include "./ft_malloc/ft_malloc.h"

# define VALID 1
# define INVALID 0
# define TRUE 1
# define FALSE 0

# define DEFAULT_ARGS_NUM 5

typedef struct s_philosopher
{
    int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
    int time_last_eat;
    int time_die;
    int num_eat_left;
} t_philosopher;


typedef struct s_philosopher_data
{
	int	num_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	is_additional_args;
}	t_philosopher_data;

typedef enum e_err
{
    NO_ERR,
	MALLOC_FAIL,

    INVALID_ARG_NUM,
    INVALID_ARG_VALUE,
    SENTINEL,
} t_err;

typedef struct s_all
{
    t_err			err;
	t_philosopher	*philosopher_arry;
	t_philosopher_data	philosopher_data;
}   t_all;

//main
void    ft_finalize(t_all *all);
void    ft_finalize(t_all *all);

//check
int is_valid_args(int argc, char **argv, t_err *err);

//process
t_err	main_process(t_all *all);

//error
int ft_error(t_all *all);

//utils
int	ft_atoi(int n, t_err *err);

#endif
