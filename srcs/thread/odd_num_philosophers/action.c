#include "../../../philosopher.h"

void	philosopher_take_fork_odd(t_philosopher *philosopher)
{
	if (philosopher->id % 2)
	{
		if (philosopher->id == 0 && philosopher->num_eaten == 1)
		{
			pthread_mutex_lock(&philosopher->mutexes->fork_id0);
			pthread_mutex_lock(philosopher->fork_left);
			pthread_mutex_unlock(&philosopher->mutexes->fork_id0);
		}
		else
			pthread_mutex_lock(philosopher->fork_left);
	}
	else
	{
		// ft_usleep(200);
		pthread_mutex_lock(philosopher->fork_left);
	}
	print_log_mutex(philosopher, MESSAGE_GET_FORK);
	pthread_mutex_lock(philosopher->fork_right);
	print_log_mutex(philosopher, MESSAGE_GET_FORK);
}

void	philosopher_eat_odd(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_EAT);
	if (philosopher->num_eat_left > 0)
		philosopher->num_eat_left--;
	philosopher->num_eaten++;
	philosopher->time_last_eat_usec = ft_get_time_usec();
	// printf("dt: %lld\n", philosopher->dt);
	update_accurate_time(&philosopher->accurate_time, philosopher->time_to_eat_usec);
	ft_usleep(philosopher->time_to_eat_usec + philosopher->accurate_time.dt);
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);	
}

void	philosopher_sleep_odd(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_SLEEP);
	update_accurate_time(&philosopher->accurate_time, philosopher->time_to_sleep_usec);
	ft_usleep(philosopher->time_to_sleep_usec + philosopher->accurate_time.dt);
}

void	philosopher_think_odd(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_THINK);
}
