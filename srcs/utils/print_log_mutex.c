#include "../../philosopher.h"

void	print_log_mutex(t_philosopher *philosopher, char *s)
{
	if (*philosopher->is_simulation_finished)
		return;
	pthread_mutex_lock(&philosopher->mutexes->print);
	philosopher->actual_time_usec = ft_get_time_usec();
	printf("%lld %d %s\n", philosopher->actual_time_usec / 1000 - philosopher->start_time, philosopher->id, s);
	pthread_mutex_unlock(&philosopher->mutexes->print);
	philosopher->dt = philosopher->ideal_time_usec - philosopher->actual_time_usec;
}
