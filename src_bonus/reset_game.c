/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_game(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->game.size.y)
	{
		j = 0;
		while (j < mlx->game.size.x)
		{
			mlx->game.map[i][j].type = mlx->game.map[i][j].og_type;
			j++;
		}
		i++;
	}
	mlx->game.moves = 0;
	mlx->game.collects = mlx->game.og_collects;
	mlx->game.hero.box = mlx->game.hero.og_box;
	mlx->game.hero.completed = FALSE;
	mlx->game.flash = 0x5F000000;
	mlx->game.flash_colour = 0xFF000000;
}
