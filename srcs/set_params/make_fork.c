#include "../../philosopher.h"

pthread_mutex_t		*make_fork(int num_philosophers, t_err *err)
{
	pthread_mutex_t	*ret;
	int				i;

	ret = ft_malloc(sizeof(pthread_mutex_t) * num_philosophers);
	if (!ret)
	{
		*err = MALLOC_FAIL;
		return (NULL);
	}
	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_init(&ret[i], NULL);
		i++;
	}
	return (ret);
}