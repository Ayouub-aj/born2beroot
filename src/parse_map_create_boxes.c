/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_create_boxes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_box	**parse_map_create_boxes(char **ss, int len, int lines, t_mlx *mlx)
{
	int		i;
	int		j;
	t_box	**box;

	box = ft_malloc(sizeof(t_box *) * lines);
	i = 0;
	while (ss[i])
	{
		box[i] = ft_malloc(sizeof(t_box) * len);
		j = 0;
		while (ss[i][j])
		{
			box[i][j].type = ss[i][j];
			box[i][j].og_type = ss[i][j];
			box[i][j].pos.x = j;
			box[i][j].pos.y = i;
			if (box[i][j].type == HERO)
				mlx->game.hero.box = &box[i][j];
			if (box[i][j].type == COLLECTABLE)
				mlx->game.collects++;
			j++;
		}
		i++;
	}
	return (box);
}
