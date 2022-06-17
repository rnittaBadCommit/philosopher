#include "../../philosopher.h"

long long int	ft_get_time_sec()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long long)tv.tv_sec * 1000 + tv.tv_usec);
}
