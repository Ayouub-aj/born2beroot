/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:57:00 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 03:36:28 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *src, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = ft_malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!str)
		return (str);
	i = 0;
	while (src[i])
	{
		str[i] = (*f)(i, src[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
