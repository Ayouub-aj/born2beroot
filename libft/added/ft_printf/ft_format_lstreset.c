/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_lstreset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 05:29:17 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 17:42:00 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format_lstreset(t_format *list)
{
	list->minwidth = 0;
	list->leftadjustment = 0;
	list->padding = ' ';
	list->precision = -1;
	list->conversion = 0;
	list->maxlen = 0;
	return (1);
}
