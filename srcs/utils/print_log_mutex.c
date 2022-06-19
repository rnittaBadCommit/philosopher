/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:59 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:06:00 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

void	print_log_mutex(t_philosopher *philosopher, char *s)
{
	pthread_mutex_lock(&philosopher->mutexes->print);
	if (!*philosopher->is_simulation_finished)
		printf("%lld %d %s\n", (ft_get_time_usec() - \
			philosopher->start_time_usec) / 1000, philosopher->id, s);
	pthread_mutex_unlock(&philosopher->mutexes->print);
}
