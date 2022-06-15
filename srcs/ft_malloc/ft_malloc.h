/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:09 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 15:24:23 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*p;
	int				index;
}				t_list;

void	*ft_malloc(size_t size);
int		ft_free(void *p);
void	ft_free_all(void);
//void    *ft_malloc_with_index(int size, int index)

#endif