/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:53:55 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/09 18:49:28 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_satoi(char const *str, int *n)
{
	short	u;
	long	ln;

	if (!str)
		return (-1);
	u = 1;
	ln = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			u = -1;
	while (ft_isdigit(*str))
		ln = ln * 10 + *str++ - '0';
	ln *= u;
	if (*str || ln < INT_MIN || ln > INT_MAX)
		return (-1);
	*n = ln;
	return (0);
}
