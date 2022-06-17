#include "../../philosopher.h"

#define NO_DEAD 0

int	_get_dead_philosopher_id(t_philosopher *philosopher_arry, int num_philosophers)
{
	int	time;
	int	i;

	time = ft_get_time_sec();
	i = 0;
	while (i < num_philosophers)
	{
		if (philosopher_arry[i].time_die <= time - philosopher_arry[i].time_last_eat)
			return (philosopher_arry[i].id);
	}
	return (NO_DEAD);
}

static int	_is_exist_not_finished_philosopher(t_philosopher *philosopher_arry, int num_philosopher)
{
	int	i;

	i = 0;
	while (i < num_philosopher)
	{
		if (philosopher_arry[i].num_eat_left != 0)
			return (1);
	}
	return (0);
}

void	*monitoring_threads(void *p)
{
	t_all			*all;
	int				dead_philosopher_id;

	all = p;
	while (1)
	{
		usleep(100);
		dead_philosopher_id = _get_dead_philosopher_id(all->philosopher_arry, all->philosopher_data.num_philosophers);
		if (dead_philosopher_id != NO_DEAD)
		{
			//死亡を検知した際の処理
			break;
		}
		if (!_is_exist_not_finished_philosopher(all->philosopher_arry, all->philosopher_data.num_philosophers))
		{
			//全員食べ終わった際の処理
		}
	}
	return (NULL);
}