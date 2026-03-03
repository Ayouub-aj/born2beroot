/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->game.size.y)
	{
		j = 0;
		while (j < mlx->game.size.x)
		{
			if (ft_abs(mlx->game.hero.box->pos.x - j) < 4
				&& ft_abs(mlx->game.hero.box->pos.y - i) < 4)
				render_box(mlx->game.map[i][j], j, i, mlx);
			j++;
		}
		i++;
	}
}
