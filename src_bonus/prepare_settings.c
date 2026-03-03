/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prepare_settings(t_mlx *mlx)
{
	mlx->game.hero.action_frames = 0;
	mlx->game.hero.framecount = 0;
	mlx->game.hero.idle_frames = 10;
	mlx->game.hero.left = 0;
	mlx->game.hero.completed = FALSE;
	mlx->game.og_collects = mlx->game.collects;
	mlx->game.flash = 0;
	mlx->hud_flash = 0;
	mlx->game.moves = 0;
	mlx->game.hero.og_box = mlx->game.hero.box;
	mlx->game.flash = 0x5F000000;
	mlx->game.flash_colour = 0xFF000000;
}
