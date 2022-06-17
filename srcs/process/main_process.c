#include "../../philosopher.h"

void	thread_main(void *p)
{
	t_philosopher *philosopher;

	philosopher = p;
	while (!*philosopher->is_finished)
	{
		philosopher_take_fork();
		philosopher_eat();
		philosopher_sleep();
		philosopher_think();
	}
}

t_err	start_threads(t_all *all)
{
	return (all->err);
}
