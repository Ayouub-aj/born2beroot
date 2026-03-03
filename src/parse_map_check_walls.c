/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_walls.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map_check_walls(char **ss, int len, int lines)
{
	int	i;

	i = -1;
	while (ss[0][++i])
		if (ss[0][i] != WALL)
			ft_exit(ft_strf("Error\nMap line 0 no WALL at %d\n", i));
	i = -1;
	while (ss[lines - 1][++i])
		if (ss[lines - 1][i] != WALL)
			ft_exit(ft_strf("Error\nMap line %d no WALL at %d\n", lines - 1, i));
	i = -1;
	while (ss[++i])
		if (ss[i][0] != WALL)
			ft_exit(ft_strf("Error\nMap line %d no WALL at 0\n", i));
	i = -1;
	while (ss[++i])
		if (ss[i][len - 1] != WALL)
			ft_exit(ft_strf("Error\nMap line %d no WALL at %d\n", i, len - 1));
}
