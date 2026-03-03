/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:58:10 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/02 20:58:11 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char			c;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		c = str[start];
		str[start++] = str[end];
		str[end--] = c;
	}
	return (str);
}
