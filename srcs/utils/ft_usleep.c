/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:53 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:05:54 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

void	ft_usleep(long long int sleep_time)
{
	long long int	start_time;
	long long int	now;

	start_time = ft_get_time_usec();
	now = start_time;
	while (now - start_time < sleep_time)
	{
		usleep(1);
		now = ft_get_time_usec();
	}
}
