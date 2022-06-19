/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_accurate_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:06:01 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:06:02 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

void	update_accurate_time(t_accurate_time *accurate_time, \
	int time_to_action)
{
	accurate_time->actual_time_usec = ft_get_time_usec();
	accurate_time->dt = (accurate_time->ideal_time_usec - \
		accurate_time->actual_time_usec) % 1000;
	accurate_time->ideal_time_usec += time_to_action;
}
