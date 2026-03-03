/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 05:28:25 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 17:42:19 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_format_putchar(char c, t_format *list, char *s)
{
	int	i;
	int	j;

	i = 0;
	while (list->minwidth-- > 1)
		i++;
	s = ft_malloc(sizeof(char) * (i + 1 + 1));
	if (!s)
		return (s);
	j = 0;
	while (!list->leftadjustment && i-- > 0)
		s[j++] = list->padding;
	s[j++] = c;
	while (list->leftadjustment && i-- > 0)
		s[j++] = ' ';
	s[j] = 0;
	return (s);
}
