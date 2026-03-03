/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 05:30:15 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 17:42:53 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_leadingzeros(int n, int r, char *str)
{
	int		i;
	int		len;

	if (r == 0 && n == 0)
		return (ft_strdup(""));
	len = ft_max(ft_nbrlen(n), r);
	str = ft_malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	i = 0;
	while (n > 9 || n < -9)
	{
		str[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	str[i++] = ft_abs(n) + '0';
	while (r - i > 0)
		str[i++] = '0';
	if (n < 0)
		str[i++] = '-';
	str[i] = 0;
	return (ft_strrev(str));
}

static char	*ft_format_putnbr_fill(t_format *list, char *s)
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

char	*ft_format_putnbr(int n, t_format *list, char *s)
{
	if (!list->leftadjustment && list->padding == '0' && list->precision < 0
		&& list->minwidth != 0)
	{
		if (n < 0)
			list->precision = list->minwidth - 1;
		else
			list->precision = list->minwidth;
	}
	s = ft_itoa_leadingzeros(n, list->precision, s);
	if (!s)
		return (s);
	list->maxlen = ft_max(ft_strlen(s), list->precision);
	s = ft_format_putnbr_fill(list, s);
	return (s);
}
