#include "../../philosopher.h"

long long int	ft_get_time_msec()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long int	ft_get_time_usec()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000000 + tv.tv_usec);
}
