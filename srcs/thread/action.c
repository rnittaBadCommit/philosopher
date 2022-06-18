#include "../../philosopher.h"

void	philosopher_take_fork(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
		pthread_mutex_lock(philosopher->fork_left);
	else
	{
		usleep(200);
		pthread_mutex_lock(philosopher->fork_left);
	}
	print_log_mutex(philosopher, MESSAGE_GET_FORK);
	pthread_mutex_lock(philosopher->fork_right);
	print_log_mutex(philosopher, MESSAGE_GET_FORK);
}

void	philosopher_eat(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_EAT);
	if (philosopher->num_eat_left > 0)
		philosopher->num_eat_left--;
	philosopher->time_last_eat = ft_get_time_msec();
	usleep(philosopher->time_to_eat + philosopher->dt);
	philosopher->dt = 0;
	philosopher->ideal_time_usec += philosopher->time_to_eat;
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);	
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_SLEEP);
	usleep(philosopher->time_to_sleep + philosopher->dt);
	philosopher->dt = 0;
	philosopher->ideal_time_usec += philosopher->time_to_sleep;
}

void	philosopher_think(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_THINK);
}
