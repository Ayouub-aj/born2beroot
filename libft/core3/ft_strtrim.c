/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:00:44 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 21:00:45 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned short	ft_set_check(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *src, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	while (src[start] && ft_set_check(src[start], set))
		start++;
	end = ft_strlen(src);
	while (end > 0 && ft_set_check(src[end - 1], set))
		end--;
	return (ft_substring(src, start, end));
}
