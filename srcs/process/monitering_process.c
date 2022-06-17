#include "../../philosopher.h"

int	_is_all_survive(s_philosopher *philosopher_arry)
{

}

void	moniter_philosophers(void *p)
{
	t_all			*all;
	t_philosopher	*philosopher_arry;
	int				i;
	int				time;

	all = p;
	while (1)
	{
		time = ft_get_time_sec();
		i = 0;
		while (i < all->philosopher_data.num_philosophers)
		{
			if (philosopher_arry[i].time_die <= time - philosopher_arry[i].time_last_eat)
				

		}
	}
}