/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:01:44 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 09:03:58 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_queue(void *data, int now)
{
	static t_list	*heap;
	t_list			*lst;

	if (data && now == 0 && !ft_lstfind(heap, data, ft_ptrcmp))
	{
		lst = ft_lstnew_malloc(data);
		if (!lst)
			data = ft_free(data);
		ft_lstadd_front(&heap, lst);
		return (data);
	}
	else if (data && now == 1)
	{
		lst = ft_lstfind(heap, data, ft_ptrcmp);
		if (lst)
			ft_lstremove_malloc(&heap, lst, free);
		else
			free(data);
	}
	else if (now == 2)
		return (heap);
	else if (now == 3)
		ft_lstclear_malloc(&heap, free);
	return (NULL);
}
