/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:59:10 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 07:36:42 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *find, int (*f)(void *, void *))
{
	while (lst)
	{
		if (!f(lst->content, find))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
