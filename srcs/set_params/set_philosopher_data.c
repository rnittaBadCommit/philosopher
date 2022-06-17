#include "../../philosopher.h"

void	set_philosopher_data(t_philosopher_data *data, \
	char **argv, t_err *err)
{
	data->num_philosophers = ft_atoi(argv[1], err);
	data->time_to_die = ft_atoi(argv[2], err);
	data->time_to_eat = ft_atoi(argv[3], err);
	data->time_to_sleep = ft_atoi(argv[4], err);
	if (argv[5] == NULL)
		data->num_eat_time = -1;
	else
		data->num_eat_time = atoi(argv[5]);
	data->start_time = ft_get_time_sec();
}
