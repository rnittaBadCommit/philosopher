#include "../../philosopher.h"

pthread_mutex_t		*make_fork(int num_philosophers)
{
	return (ft_malloc(sizeof(pthread_mutex_t *) * num_philosophers));
}