/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:00:50 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 03:36:46 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*str;

	if (ft_strnlen(src, start) == start)
		len = ft_strnlen(src + start, len);
	else
		len = 0;
	str = ft_malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	ft_memcpy(str, src + start, len);
	str[len] = 0;
	return (str);
}
