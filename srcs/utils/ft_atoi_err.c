/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:05:47 by rnitta            #+#    #+#             */
/*   Updated: 2022/06/19 15:05:47 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosopher.h"

static unsigned int	_convert_to_absolute(char *s, int sign, t_err *err)
{
	unsigned int	ret;

	ret = 0;
	while ('0' <= *s && *s <= '9')
	{
		if (ret > (unsigned int)(INT_MAX + (sign == -1) - (*s - '0')) / 10)
		{
			*err = OVER_FLOW;
			return (INT_MAX + (sign == -1));
		}
		ret = ret * 10 + (*s - '0');
		s++;
	}
	return (ret);
}

int	ft_atoi(char *s, t_err *err)
{
	int	sign;

	if (s == NULL)
	{
		*err = INPUT_NULL_POINTER;
		return (0);
	}
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '\0')
	{
		*err = NO_DIGITS;
		return (0);
	}
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else
		sign = 1;
	return ((int)_convert_to_absolute(s, sign, err) * sign);
}
