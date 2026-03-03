/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->bgr_img->ptr, 0, 0);
	render_map(mlx);
	if (!mlx->game.hero.completed)
		render_hero(mlx);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->shade->ptr,
		calc_hmove_x(mlx) - 350, calc_hmove_y(mlx) - 350);
	if (mlx->game.flash > 0)
	{
		if (mlx->game.flash < 16777216)
			mlx->game.flash = 0;
		else
			mlx->game.flash -= 16777216;
		fill_square_img(mlx->game.flash_img, mlx->win_w, mlx->win_h,
			mlx->game.flash_colour - mlx->game.flash);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.flash_img->ptr,
			0, 0);
	}
	hud(mlx);
	return (0);
}
