#include "../../philosopher.h"

static void	_change_time_us_to_ms(t_philosopher_data *data, t_err *err)
{
	if (
		data->time_to_eat > INT_MAX / 1000 || \
		data->time_to_sleep > INT_MAX / 1000)
	{
		*err = OVER_FLOW;
		return;
	}
	data->time_to_eat *= 1000;
	data->time_to_sleep *= 1000;
}

void	set_philosopher_data(t_philosopher_data *data, \
	char **argv, t_err *err)
{
	data->num_philosophers = ft_atoi(argv[1], err);
	data->time_to_die = ft_atoi(argv[2], err);
	data->time_to_eat = ft_atoi(argv[3], err);
	data->time_to_sleep = ft_atoi(argv[4], err);
	_change_time_us_to_ms(data, err);
	if (argv[5] == NULL)
		data->num_eat_time = -1;
	else
		data->num_eat_time = atoi(argv[5]);
	data->start_time = ft_get_time_msec();
	pthread_mutex_init(&data->mutexes.print, NULL);
	data->is_simutation_finished = 0;
}
