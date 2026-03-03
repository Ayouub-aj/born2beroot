/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrisunq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:01:07 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 13:51:19 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arrisunq(int *array, int count)
{
	int	i;
	int	*sorted;

	sorted = ft_arrbbl(ft_arrdup(array, count), count);
	i = 0;
	while (i < count - 1)
	{
		if (sorted[i] == sorted[i + 1])
		{
			sorted = ft_free(sorted);
			return (0);
		}
		i++;
	}
	sorted = ft_free(sorted);
	return (1);
}
