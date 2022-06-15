#include "../../philosopher.h"

void	ft_bzero(void *p, size_t size)
{
	char *s;

	s = (char *)p;
	while (size-- > 0)
	{
		*s = 0;
		s++;
	}
}

