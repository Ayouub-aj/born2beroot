/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:53:45 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 20:53:47 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned int	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i++ < n)
		((char *)dst)[i - 1] = ((char *)src)[i - 1];
	return (dst);
}
