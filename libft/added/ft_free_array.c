/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:52:27 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 01:25:03 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_int_array(int **array, int size)
{
	while (size-- > 0)
		array[size] = ft_free(array[size]);
	array = ft_free(array);
	return (NULL);
}
