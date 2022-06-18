#include "../../philosopher.h"

t_err	set_all(t_all *all, char **argv)
{
	all->err = NO_ERR;
	set_philosopher_data(&all->philosopher_data, argv, &all->err);
	if (all->err)
		return (all->err);
	all->fork = make_fork(all->philosopher_data.num_philosophers, &all->err);
	if (all->err)
		return (all->err);
	all->philosopher_arry = make_philosopher_arry(all->philosopher_data.num_philosophers, &all->err);
	if (all->err)
		return (all->err);
	set_philosopher_arry(all->philosopher_arry, &all->philosopher_data, all->fork);
	return (NO_ERR);
}
