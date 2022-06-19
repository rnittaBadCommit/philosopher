/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:53 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 16:34:53 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

void	ft_usleep(long long int sleep_time)
{
	long long int	start_time;
	long long int	now;
	long long int	_sleep_time;

	start_time = ft_get_time_usec();
	now = start_time;
	_sleep_time = sleep_time;
	while (now - start_time < sleep_time)
	{
		if (_sleep_time > 50)
		{
			usleep(_sleep_time / 2);
			now = ft_get_time_usec();
			_sleep_time = (now - start_time) / 2;
		}
		else
		{
			usleep(50);
			now = ft_get_time_usec();
		}
	}
}
