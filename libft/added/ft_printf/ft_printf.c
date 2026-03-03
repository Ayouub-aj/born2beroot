/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 05:30:51 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/09 18:23:19 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strchr_mod(char const *s, int c)
{
	char	*chr;

	chr = ft_strchr(s, c);
	if (!chr)
		return (ft_strchr(s, '\0'));
	return (chr);
}

static char	*ft_parse_format(char const *format, va_list *va, t_format *list,
	char *s)
{
	char	*chr;

	if (!*format)
		return (ft_strdup(""));
	while (*format)
	{
		if (*format == '%' && ft_format_lstreset(list))
			s = ft_strjoin_free(s, ft_conversion_read(&format, va, list, s));
		else
		{
			chr = ft_strchr_mod(format, '%');
			s = ft_strjoin_free(s, ft_substr(format, 0, chr - format));
			format = chr - 1;
		}
		if (!s)
			return (s);
		format++;
	}
	return (s);
}

int	ft_printf(char const *format, ...)
{
	t_format	*list;
	char		*s;
	va_list		va;
	int			count;

	list = ft_format_lstnew();
	if (!list)
		return (-1);
	s = NULL;
	va_start(va, format);
	s = ft_parse_format(format, &va, list, s);
	va_end(va);
	if (!s)
		return (-1);
	count = ft_putstr(s);
	list = ft_free(list);
	s = ft_free(s);
	return (count);
}
