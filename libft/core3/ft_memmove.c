/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:53:52 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 20:53:53 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (n-- > 0)
			((char *)dst)[n] = ((char *)src)[n];
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
