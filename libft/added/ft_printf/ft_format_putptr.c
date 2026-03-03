/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 05:30:36 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 18:28:32 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_format_putptr_hex(uintptr_t q, int r, char *str)
{
	int			uilen;
	int			j;
	int			len;

	if (r == 0 && q == 0)
		return (ft_strdup("0x"));
	j = 0;
	uilen = sizeof(q) * 2;
	while (j < uilen - 1 && !((q >> ((uilen - 1 - j) * 4)) & 0xf))
		j++;
	len = uilen - j;
	str = ft_malloc(sizeof(char) * (ft_max(len, r) + 3));
	if (!str)
		return (str);
	j = 0;
	str[j++] = '0';
	str[j++] = 'x';
	while (r-- > len)
		str[j++] = '0';
	while (len > 0)
		str[j++] = "0123456789abcdef"[(q >> ((len-- - 1) * 4)) & 0xf];
	str[j] = 0;
	return (str);
}

static char	*ft_format_putptr_fill(t_format *list, char *s)
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
		str[j++] = ' ';
	while (s[k])
		str[j++] = s[k++];
	s = ft_free(s);
	while (list->leftadjustment && i-- > 0)
		str[j++] = ' ';
	str[j] = 0;
	return (str);
}

char	*ft_format_putptr(void *p, t_format *list, char *s)
{
	s = ft_format_putptr_hex((uintptr_t)p, list->precision, s);
	if (!s)
		return (s);
	list->maxlen = ft_max(ft_strlen(s), list->precision);
	s = ft_format_putptr_fill(list, s);
	return (s);
}
