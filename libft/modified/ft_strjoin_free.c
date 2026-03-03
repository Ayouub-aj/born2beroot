/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:58:58 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 05:58:20 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	if (s1 && s2)
		str = ft_strjoin(s1, s2);
	else if (s1)
	{
		str = ft_strdup(s1);
		s1 = ft_free(s1);
	}
	else if (s2)
	{
		str = ft_strdup(s2);
		s2 = ft_free(s2);
	}
	else
		return (NULL);
	s1 = ft_free(s1);
	s2 = ft_free(s2);
	return (str);
}
