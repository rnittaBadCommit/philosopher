/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:12 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 17:33:33 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

static void	_ini_all(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
}

void	ft_finalize(t_all *all)
{
	if (all)
		ft_free_all();
}

int	main(int argc, char **argv)
{
	t_all	all;

	_ini_all(&all);
	if (!is_valid_args(argc, argv, &all.err))
		return (ft_error(&all));
	if (set_all(&all, argv) != NO_ERR)
		return (ft_error(&all));
	if (all.philosopher_data.num_eat_time == 0 || \
			all.philosopher_data.num_philosophers == 0)
		;
	else if (all.philosopher_data.num_philosophers == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("%d 1 died\n", all.philosopher_data.time_to_die / 1000);
	}
	else if (all.philosopher_data.num_philosophers % 2)
	{
		if (start_threads_odd_num(&all) != NO_ERR)
			return (ft_error(&all));
	}
	else
		if (start_threads_even_num(&all) != NO_ERR)
			return (ft_error(&all));
	ft_finalize(&all);
	return (0);
}
