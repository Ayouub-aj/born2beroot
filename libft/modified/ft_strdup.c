/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:55:34 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/08 03:34:51 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	char	*str;

	str = ft_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (str);
	return (ft_strcpy(str, s));
}
