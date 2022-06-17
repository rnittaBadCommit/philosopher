#include "../../philosopher.h"

void	printf_mutex(int id, char *s, pthread_mutex_t *mutex_print, long long int start_time)
{
	pthread_mutex_lock(mutex_print);
	printf("%lld %d %s", ft_get_time_sec() - start_time, id, s);
	pthread_mutex_unlock(mutex_print);
}
