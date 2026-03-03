/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:54 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 03:34:05 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_strings(char **strings)
{
	char	**s;

	s = strings;
	while (*s)
	{
		*s = ft_free(*s);
		s++;
	}
	*s = ft_free(*s);
	strings = ft_free(strings);
	return (strings);
}
