#include "../../philosopher.h"

void	philosopher_take_fork(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
		pthread_mutex_lock(philosopher->fork_left);
	else
	{
		// ft_usleep(200);
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
	philosopher->time_last_eat_usec = ft_get_time_usec();
	// printf("dt: %lld\n", philosopher->dt);
	philosopher->actual_time_usec = ft_get_time_usec();
	philosopher->dt = philosopher->ideal_time_usec - philosopher->actual_time_usec;
	ft_usleep(philosopher->time_to_eat_usec + philosopher->dt);
	philosopher->dt = 0;
	philosopher->ideal_time_usec += philosopher->time_to_eat_usec;
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);	
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_SLEEP);
	philosopher->actual_time_usec = ft_get_time_usec();
	philosopher->dt = philosopher->ideal_time_usec - philosopher->actual_time_usec;
	ft_usleep(philosopher->time_to_sleep_usec + philosopher->dt);
	philosopher->dt = 0;
	philosopher->ideal_time_usec += philosopher->time_to_sleep_usec;
}

void	philosopher_think(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_THINK);
}
