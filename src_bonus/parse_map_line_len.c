/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map_line_len(char **s)
{
	int	len;
	int	i;

	i = 0;
	len = -1;
	while (s[i])
	{
		if (len >= 0 && len != (int)ft_strlen(s[i]))
			ft_exit(ft_strf("Error\nMap line %d len is wrong %d\n", i,
					ft_strlen(s[i])));
		len = ft_strlen(s[i]);
		i++;
	}
	return (len);
}
