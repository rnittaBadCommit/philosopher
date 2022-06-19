#include "../../philosopher.h"

void	print_log_mutex(t_philosopher *philosopher, char *s)
{
	pthread_mutex_lock(&philosopher->mutexes->print);
	// philosopher->actual_time_usec = ft_get_time_usec();
	if (!*philosopher->is_simulation_finished)
		printf("%lld %d %s\n", (ft_get_time_usec() - philosopher->start_time_usec) / 1000 , philosopher->id, s);
	pthread_mutex_unlock(&philosopher->mutexes->print);
	// printf("ideal_time: %lld, dt: %lld\n", philosopher->ideal_time_usec - philosopher->start_time_usec, philosopher->dt);
}
