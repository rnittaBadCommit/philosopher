#include "../../philosopher.h"

void	*thread_main(void *p)
{
	t_philosopher *philosopher;

	philosopher = p;
	while (!*philosopher->is_simulation_finished)
	{
		philosopher_take_fork(philosopher);
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
	}
	return (NULL);
}

t_err	start_threads(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->philosopher_data.num_philosophers)
	{
		pthread_create(&all->philosopher_arry[i].thread, NULL, &thread_main, (void *)&all->philosopher_arry[i]);
		i++;
	}
	pthread_create(&all->monitoring_thread, NULL, &monitoring_threads, (void *)all);
	i = 0;
	while (i < all->philosopher_data.num_philosophers)
	{
		pthread_join(all->philosopher_arry[i].thread, NULL);
		i++;
	}
	pthread_join(all->monitoring_thread, NULL);
	return (NO_ERR);
}
