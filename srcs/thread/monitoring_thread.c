/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:43 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:05:44 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

#define NO_DEAD 0

void	_print_log_mutex(t_philosopher *philosopher, char *s)
{
	pthread_mutex_lock(&philosopher->mutexes->print);
	printf("%lld %d %s\n", (ft_get_time_usec() - \
		philosopher->start_time_usec) / 1000, philosopher->id, s);
	pthread_mutex_unlock(&philosopher->mutexes->print);
}

int	_get_dead_philosopher_id(t_philosopher *philosopher_arry, \
	int num_philosophers)
{
	long long int	now;
	int				i;

	now = ft_get_time_usec();
	i = 0;
	while (i < num_philosophers)
	{
		if (philosopher_arry[i].time_to_die_usec <= \
			now - philosopher_arry[i].time_last_eat_usec)
		{
			return (philosopher_arry[i].id);
		}
		i++;
	}
	return (NO_DEAD);
}

static int	_is_exist_not_finished_philosopher(t_philosopher \
	*philosopher_arry, int num_philosopher)
{
	int	i;

	i = 0;
	while (i < num_philosopher)
	{
		if (philosopher_arry[i].num_eat_left != 0)
			return (1);
		i++;
	}
	return (0);
}

static void	_monitoring_threads_loop(t_all *all, t_accurate_time accurate_time)
{
	int	dead_philosopher_id;

	while (1)
	{
		update_accurate_time(&accurate_time, 1000);
		ft_usleep(1000 + accurate_time.dt);
		dead_philosopher_id = _get_dead_philosopher_id(all->philosopher_arry, \
			all->philosopher_data.num_philosophers);
		if (dead_philosopher_id != NO_DEAD)
		{
			all->philosopher_data.is_simutation_finished = 1;
			_print_log_mutex(&all->philosopher_arry[dead_philosopher_id - 1], \
				MESSAGE_DIE);
			break ;
		}
		if (!_is_exist_not_finished_philosopher(all->philosopher_arry, \
			all->philosopher_data.num_philosophers))
		{
			all->philosopher_data.is_simutation_finished = 1;
			break ;
		}
	}
}

void	*monitoring_threads(void *p)
{
	t_all			*all;
	t_accurate_time	accurate_time;

	all = p;
	all->philosopher_data.start_time_usec = ft_get_time_usec();
	all->philosopher_data.is_simulation_started = 1;
	usleep(800);
	accurate_time.ideal_time_usec = \
		all->philosopher_data.start_time_usec + 1800;
	_monitoring_threads_loop(all, accurate_time);
	return (NULL);
}
