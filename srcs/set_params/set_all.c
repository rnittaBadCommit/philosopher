#include "../../philosopher.h"

t_err	set_all(t_all *all, char **argv)
{
	if (set_philosophers(all, argv) != NO_ERR)
		return (all->err);
	
	return (NO_ERR);
}
