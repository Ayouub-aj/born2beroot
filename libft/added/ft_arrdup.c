/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 19:40:06 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/09 19:44:40 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arrdup(int *array, int count)
{
	int	i;
	int	*new;

	new = ft_malloc(sizeof(int) * count);
	if (!new)
		return (new);
	i = 0;
	while (i < count)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}
