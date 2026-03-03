/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_hero2(t_mlx *mlx)
{
	if (mlx->game.hero.action_frames > 0)
	{
		mlx->game.hero.current_img = mlx->game.hero.action_img_r;
		mlx->game.hero.action_frames--;
	}
	else
	{
		mlx->game.hero.framecount++;
		if (mlx->game.hero.framecount > mlx->game.hero.idle_frames)
			mlx->game.hero.current_img = mlx->game.hero.idle_img_0_r;
		if (mlx->game.hero.framecount > mlx->game.hero.idle_frames * 2)
		{
			mlx->game.hero.current_img = mlx->game.hero.idle_img_1_r;
			mlx->game.hero.framecount = 0;
		}
	}
}

void	render_hero(t_mlx *mlx)
{
	if (mlx->game.hero.left == 1)
	{
		if (mlx->game.hero.action_frames > 0)
		{
			mlx->game.hero.current_img = mlx->game.hero.action_img_l;
			mlx->game.hero.action_frames--;
		}
		else
		{
			mlx->game.hero.framecount++;
			if (mlx->game.hero.framecount > mlx->game.hero.idle_frames)
				mlx->game.hero.current_img = mlx->game.hero.idle_img_0_l;
			if (mlx->game.hero.framecount > mlx->game.hero.idle_frames * 2)
			{
				mlx->game.hero.current_img = mlx->game.hero.idle_img_1_l;
				mlx->game.hero.framecount = 0;
			}
		}
	}
	else
		render_hero2(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.hero.current_img,
		calc_hmove_x(mlx), calc_hmove_y(mlx));
}
