/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:31:40 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 18:47:53 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_minwidth(char const **format, va_list *va, t_format *list)
{
	int	x;
	int	y;

	x = 0;
	if (**format == '*')
	{
		y = va_arg(*va, int);
		if (y < 0)
		{
			list->leftadjustment = 1;
			return (ft_abs(y));
		}
		else
			return (y);
	}
	while (ft_isdigit(**format))
		x = x * 10 + *(*format)++ - '0';
	(*format)--;
	return (x);
}

static int	ft_precision(char const **format, va_list *va)
{
	int	x;

	x = 0;
	if (*++(*format) == '*')
		return (va_arg(*va, int));
	while (ft_isdigit(**format))
		x = x * 10 + *(*format)++ - '0';
	(*format)--;
	return (x);
}

static char	*ft_conversion_write(va_list *va, t_format *list, char *s)
{
	if (list->conversion == 'd' || list->conversion == 'i')
		s = ft_format_putnbr(va_arg(*va, int), list, s);
	else if (list->conversion == 'u')
		s = ft_format_putnbr_uint(va_arg(*va, unsigned int), list, s);
	else if (list->conversion == 'x' || list->conversion == 'X')
		s = ft_format_puthex(va_arg(*va, unsigned int), list, s);
	else if (list->conversion == 's')
		s = ft_format_putstr(va_arg(*va, char *), list, s);
	else if (list->conversion == 'c')
		s = ft_format_putchar(va_arg(*va, int), list, s);
	else if (list->conversion == 'p')
		s = ft_format_putptr(va_arg(*va, void *), list, s);
	else if (list->conversion == '%')
	{
		list->precision = 1;
		s = ft_format_putstr("%", list, s);
	}
	return (s);
}

char	*ft_conversion_read(char const **format, va_list *va,
	t_format *list, char *s)
{
	(*format)++;
	while (!ft_strchr("cspdiuxX%", **format))
	{
		if ((**format > '0' && **format <= '9') || **format == '*')
			list->minwidth = ft_minwidth(format, va, list);
		else if (**format == '-')
			list->leftadjustment = 1;
		else if (**format == '0')
			list->padding = '0';
		else if (**format == '.')
			list->precision = ft_precision(format, va);
		else
			return (NULL);
		(*format)++;
	}
	list->conversion = **format;
	return (ft_conversion_write(va, list, s));
}
