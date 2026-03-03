/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:58:59 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/07 18:59:00 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst, t_list *remove, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == remove)
	{
		*lst = (*lst)->next;
		ft_lstdelone(remove, del);
	}
	else
	{
		temp = *lst;
		while (temp->next)
		{
			if (temp->next == remove)
			{
				temp->next = remove->next;
				ft_lstdelone(remove, del);
			}
			else
				temp = temp->next;
		}
	}
}
