/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 05:30:04 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 17:43:33 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_format_putstr_fill(t_format *list, char *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	while (list->minwidth-- > list->maxlen)
		i++;
	str = ft_malloc(sizeof(char) * (i + ft_strlen(s) + 1));
	if (!str)
		return (str);
	j = 0;
	k = 0;
	while (!list->leftadjustment && i-- > 0)
		str[j++] = list->padding;
	while (s[k] && list->precision-- != 0)
		str[j++] = s[k++];
	s = ft_free(s);
	while (list->leftadjustment && i-- > 0)
		str[j++] = ' ';
	str[j] = 0;
	return (str);
}

char	*ft_format_putstr(char const *str, t_format *list, char *s)
{
	if (str)
		s = ft_strdup(str);
	else
		s = ft_strdup("(null)");
	if (!s)
		return (s);
	if (list->precision < 0)
		list->maxlen = ft_strlen(s);
	else
		list->maxlen = ft_min(ft_strlen(s), list->precision);
	s = ft_format_putstr_fill(list, s);
	return (s);
}
