#include "../../philosopher.h"

static void	_set_philosopher_arry(t_philosopher *philosopher_arry, \
	t_philosopher_data data, char **argv, t_err *err)
{
	int	i;

	i = 0;
	while (i < data.num_philosophers)
	{
		philosopher_arry[i].time_to_die = data.time_to_die;
		philosopher_arry[i].time_to_eat = data.time_to_eat;
		philosopher_arry[i].time_to_sleep = data.time_to_sleep;
		philosopher_arry[i].time_last_eat = 0;
		philosopher_arry[i].time_die = 0 + data.time_to_die;
		if (data.is_additional_args)
			philosopher_arry[i].num_eat_left = ft_atoi(argv[5 + i], err);
		else
			philosopher_arry[i].num_eat_left = -1;
		i++;
	}
}

static void	_set_philosopher_data(t_philosopher_data *data, \
	char **argv, t_err *err)
{
	data->num_philosophers = ft_atoi(argv[1], err);
	data->time_to_die = ft_atoi(argv[2], err);
	data->time_to_eat = ft_atoi(argv[3], err);
	data->time_to_sleep = ft_atoi(argv[4], err);
	data->is_additional_args = (argv[5] != NULL);
}

static t_philosopher	*_make_philosopher_arry(int num_philosophers, \
	t_err *err)
{
	t_philosopher	*ret;

	ret = ft_malloc(sizeof(t_philosopher) * (num_philosophers + 1));
	if (ret == NULL)
		*err = MALLOC_FAIL;
	return (ret);
}

t_err	set_philosophers(t_all *all, char **argv)
{
	_set_philosopher_data(&all->philosopher_data, argv, &all->err);
	all->philosopher_arry = _make_philosopher_arry(\
		all->philosopher_data.num_philosophers, &all->err);
	if (all->err != NO_ERR)
		return (all->err);
	_set_philosopher_arry(all->philosopher_arry, \
		all->philosopher_data, argv, &all->err);
	return (all->err);
}
