#include "../../philosopher.h"

static void	_change_time_ms_to_us(t_philosopher_data *data, t_err *err)
{
	if (
		data->time_to_eat_usec > INT_MAX / 1000 || \
		data->time_to_sleep_usec > INT_MAX / 1000 || \
		data->time_to_die > INT_MAX / 1000)
	{
		*err = OVER_FLOW;
		return;
	}
	data->time_to_eat_usec *= 1000;
	data->time_to_sleep_usec *= 1000;
	data->time_to_die *= 1000;
}

void	set_philosopher_data(t_philosopher_data *data, \
	char **argv, t_err *err)
{
	data->num_philosophers = ft_atoi(argv[1], err);
	data->time_to_die = ft_atoi(argv[2], err);
	data->time_to_eat_usec = ft_atoi(argv[3], err);
	data->time_to_sleep_usec = ft_atoi(argv[4], err);
	_change_time_ms_to_us(data, err);
	if (argv[5] == NULL)
		data->num_eat_time = -1;
	else
		data->num_eat_time = atoi(argv[5]);
	pthread_mutex_init(&data->mutexes.print, NULL);
	data->is_simutation_finished = 0;
}
