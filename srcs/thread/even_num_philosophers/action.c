#include "../../../philosopher.h"

void	philosopher_take_fork_even(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->fork_left);
	print_log_mutex(philosopher, MESSAGE_GET_FORK);
	pthread_mutex_lock(philosopher->fork_right);
	print_log_mutex(philosopher, MESSAGE_GET_FORK);
}

void	philosopher_eat_even(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_EAT);
	if (philosopher->num_eat_left > 0)
		philosopher->num_eat_left--;
	philosopher->time_last_eat_usec = ft_get_time_usec();
	// printf("dt: %lld\n", philosopher->dt);
	update_accurate_time(&philosopher->accurate_time, philosopher->time_to_eat_usec);
	ft_usleep(philosopher->time_to_eat_usec + philosopher->accurate_time.dt);
	pthread_mutex_unlock(philosopher->fork_left);
	pthread_mutex_unlock(philosopher->fork_right);
}

void	philosopher_sleep_even(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_SLEEP);
	update_accurate_time(&philosopher->accurate_time, philosopher->time_to_sleep_usec);
	ft_usleep(philosopher->time_to_sleep_usec + philosopher->accurate_time.dt);
}

void	philosopher_think_even(t_philosopher *philosopher)
{
	print_log_mutex(philosopher, MESSAGE_THINK);
}
