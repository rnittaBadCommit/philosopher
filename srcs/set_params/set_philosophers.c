/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:26 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:05:27 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

void	set_philosopher_arry(t_philosopher *philosopher_arry, \
	t_philosopher_data *data, pthread_mutex_t *fork)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		philosopher_arry[i].time_to_die_usec = data->time_to_die;
		philosopher_arry[i].time_to_eat_usec = data->time_to_eat_usec;
		philosopher_arry[i].time_to_sleep_usec = data->time_to_sleep_usec;
		philosopher_arry[i].time_last_eat_usec = data->start_time_usec;
		philosopher_arry[i].time_die = 0 + data->time_to_die;
		philosopher_arry[i].num_eat_left = data->num_eat_time;
		philosopher_arry[i].id = i + 1;
		philosopher_arry[i].start_time_addr = &data->start_time_usec;
		if (i == 0)
			philosopher_arry[i].fork_left = &fork[data->num_philosophers - 1];
		else
			philosopher_arry[i].fork_left = &fork[i - 1];
		philosopher_arry[i].fork_right = &fork[i];
		philosopher_arry[i].mutexes = &data->mutexes;
		philosopher_arry[i].is_simulation_started = \
			&data->is_simulation_started;
		philosopher_arry[i].is_simulation_finished = \
			&data->is_simutation_finished;
		philosopher_arry[i].num_philosopher = data->num_philosophers;
	}
}

t_philosopher	*make_philosopher_arry(int num_philosophers, \
	t_err *err)
{
	t_philosopher	*ret;

	ret = ft_malloc(sizeof(t_philosopher) * (num_philosophers + 1));
	if (ret == NULL)
		*err = MALLOC_FAIL;
	return (ret);
}
