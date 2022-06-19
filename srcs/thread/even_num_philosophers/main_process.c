/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:32 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 18:45:21 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../philosopher.h"

static void	_set_philosopher(t_philosopher *philosopher)
{
	philosopher->start_time_usec = *philosopher->start_time_addr;
	philosopher->time_last_eat_usec = philosopher->start_time_usec;
	if (philosopher->id % 2)
		philosopher->accurate_time.ideal_time_usec = \
			philosopher->start_time_usec;
	else
		philosopher->accurate_time.ideal_time_usec = \
			philosopher->start_time_usec + philosopher->time_to_eat_usec;
}

static void	*_thread_main(void *p)
{
	t_philosopher	*philosopher;

	philosopher = p;
	while (!*philosopher->is_simulation_started)
		usleep(10);
	_set_philosopher(philosopher);
	if (philosopher->id % 2 == 0)
		usleep(philosopher->time_to_eat_usec * 3 / 4);
	while (!*philosopher->is_simulation_finished)
	{
		philosopher_take_fork_even(philosopher);
		philosopher_eat_even(philosopher);
		philosopher_sleep_even(philosopher);
		philosopher_think_even(philosopher);
	}
	return (NULL);
}

t_err	start_threads_even_num(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->philosopher_data.num_philosophers)
	{
		pthread_create(&all->philosopher_arry[i].thread, NULL, \
			&_thread_main, (void *)&all->philosopher_arry[i]);
		i++;
	}
	usleep(500);
	pthread_create(&all->monitoring_thread, NULL, \
		&monitoring_threads, (void *)all);
	i = 0;
	while (i < all->philosopher_data.num_philosophers)
	{
		pthread_join(all->philosopher_arry[i].thread, NULL);
		i++;
	}
	pthread_join(all->monitoring_thread, NULL);
	return (NO_ERR);
}
