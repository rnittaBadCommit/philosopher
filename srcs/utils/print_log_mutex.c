#include "../../philosopher.h"

void	print_log_mutex(t_philosopher *philosopher, char *s)
{
	if (philosopher->is_simulation_finished)
		return;
	pthread_mutex_lock(&philosopher->mutexes->print);
	printf("%lld %d %s", ft_get_time_sec() - philosopher->start_time, philosopher->id, s);
	pthread_mutex_unlock(&philosopher->mutexes->print);
}
