#include "../../philosopher.h"

void	set_philosopher_arry(t_philosopher *philosopher_arry, \
	t_philosopher_data *data, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		philosopher_arry[i].time_to_die = data->time_to_die;
		philosopher_arry[i].time_to_eat = data->time_to_eat;
		philosopher_arry[i].time_to_sleep = data->time_to_sleep;
		philosopher_arry[i].time_last_eat = data->start_time;
		philosopher_arry[i].time_die = 0 + data->time_to_die;
		philosopher_arry[i].num_eat_left = data->num_eat_time;
		philosopher_arry[i].id = i + 1;
		philosopher_arry[i].start_time = data->start_time;
		if (i == 0)
			philosopher_arry[i].fork_left = &fork[data->num_philosophers - 1];
		else
			philosopher_arry[i].fork_left = &fork[i - 1];
		philosopher_arry[i].fork_right = &fork[i];
		philosopher_arry[i].mutexes = &data->mutexes;
		philosopher_arry[i].is_simulation_finished = &data->is_simutation_finished;
		if (philosopher_arry[i].id % 2)
			philosopher_arry[i].ideal_time_usec = data->start_time;
		else
			philosopher_arry[i].ideal_time_usec = data->start_time + data->time_to_eat;
		philosopher_arry[i].dt = 0;
		i++;
	}
}

t_philosopher	*make_philosopher_arry(int num_philosophers, \
	t_err *err)
{
	t_philosopher	*ret;

	ret = ft_malloc(sizeof(t_philosopher) * (num_philosophers + 1));
	if (ret == NULL)
		*err = MALLOC_FAIL;
	return (ret);
}
