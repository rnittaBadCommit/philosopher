#include "../../philosopher.h"

void	ft_usleep(long long int sleep_time)
{
	long long int	start_time;
	long long int	now;

	start_time = ft_get_time_usec();
	now = start_time;
	while (now - start_time < sleep_time)
	{
		usleep(50);
		now = ft_get_time_usec();
	}
}
