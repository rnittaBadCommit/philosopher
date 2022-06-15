/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnitta <rnitta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 01:23:00 by rnitta            #+#    #+#             */
/*   Updated: 2022/04/21 15:24:28 by rnitta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	ft_bzero(void *ss, size_t size)
{
	char	*s;

	s = (char *)ss;
	while (size--)
		s[size] = 0;
}

t_list	*save_list()
{
	static t_list	save;

	return (&save);
}

static void	_add_malloc_list(void *new, int index)
{
	t_list	*list;
	t_list	*tmp;

	list = save_list();
	tmp = list->next;
	list->next = malloc(sizeof(t_list));
	list->next->next = tmp;
	list->next->p = new;
	list->next->index = index;
}

void	*ft_malloc(size_t size)
{
	void	*ret;
	int     index;

	index = 0;
	if (!size)
		return (NULL);
	ret = malloc(size);
	ft_bzero(ret, size);
	_add_malloc_list(ret, index);
	return (ret);
}

//どこでmallocしたものかを保存したい場合
//void	*ft_malloc_with_index(int size, int index)
// {
//	void	*ret;

//	if (!size)
//		return (NULL);
//	ret = malloc(size);
//	ft_bzero(ret, size);
//	add_malloc_list(ret, index);
//	return (ret);
// }
