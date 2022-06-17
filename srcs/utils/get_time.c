#include "../../philosopher.h"

int	ft_get_time_sec()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec);
}
