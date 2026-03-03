/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:56:30 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 20:56:37 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		if (i + 1 < dstsize)
			dst[i] = src[i];
		i++;
	}
	if (i + 1 < dstsize)
		dstsize = i + 1;
	if (dstsize > 0)
		dst[dstsize - 1] = 0;
	return (i);
}
