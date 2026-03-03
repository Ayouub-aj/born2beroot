/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:53:20 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/07 22:36:12 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	void			*chr;
	unsigned int	i;

	chr = ft_memchr(src, c, n);
	if (dst == src)
		return (chr);
	i = 0;
	if (chr)
	{
		while (src + i++ != chr)
			((char *)dst)[i - 1] = ((char *)src)[i - 1];
		((char *)dst)[i - 1] = ((char *)src)[i - 1];
		return (dst + i);
	}
	else
	{
		while (i++ < n)
			((char *)dst)[i - 1] = ((char *)src)[i - 1];
		return (NULL);
	}
}
