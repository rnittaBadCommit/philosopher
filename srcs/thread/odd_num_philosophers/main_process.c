/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:38 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:31:08 by rnitta           ###   ########.fr       */
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
	philosopher->num_eaten = 1;
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
	if (philosopher->id == philosopher->num_philosopher)
	{
		usleep(philosopher->time_to_eat_usec / 2);
		pthread_mutex_lock(&philosopher->mutexes->fork_id0);
	}
	while (!*philosopher->is_simulation_finished)
	{
		philosopher_take_fork_odd(philosopher);
		if (philosopher->id == philosopher->num_eat_left && \
			philosopher->num_eaten == 0)
			pthread_mutex_unlock(&philosopher->mutexes->fork_id0);
		philosopher_eat_odd(philosopher);
		philosopher_sleep_odd(philosopher);
		philosopher_think_odd(philosopher);
	}
	return (NULL);
}

t_err	start_threads_odd_num(t_all *all)
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
