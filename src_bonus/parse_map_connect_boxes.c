/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_connect_boxes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map_connect_boxes(int len, int lines, t_mlx *mlx)
{
	int		i;
	int		j;
	t_box	**box;

	box = mlx->game.map;
	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < len)
		{
			if (i != 0)
				box[i][j].up = &box[i - 1][j];
			if (i + 1 < lines)
				box[i][j].down = &box[i + 1][j];
			if (j != 0)
				box[i][j].left = &box[i][j - 1];
			if (j + 1 < len)
				box[i][j].right = &box[i][j + 1];
			j++;
		}
		i++;
	}
}
