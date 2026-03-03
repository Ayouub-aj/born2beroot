/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_mlx *mlx, t_box *box)
{
	if (box->type == WALL)
		return (0);
	else if (box->type == EXIT && mlx->game.collects > 0)
		return (0);
	else if (box->type == EXIT && mlx->game.collects <= 0)
		mlx->game.hero.completed = TRUE;
	else if (box->type == COLLECTABLE && !mlx->game.hero.completed)
	{
		box->type = EMPTY;
		mlx->game.collects--;
		if (!mlx->game.collects)
		{
			mlx->game.flash = 520093696;
			mlx->game.flash_colour = 0xFFEFFFE0;
		}
	}
	else if (box->type == MUSHROOM && !mlx->game.hero.completed)
	{
		mlx->game.flash = 520093696;
		mlx->game.flash_colour = 0xFFFF0000;
		mlx->game.hero.completed = TRUE;
	}
	mlx->game.hero.box = box;
	return (1);
}
