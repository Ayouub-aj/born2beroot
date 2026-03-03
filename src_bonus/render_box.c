/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_box(t_box box, int x, int y, t_mlx *mlx)
{
	if (box.type == EMPTY || box.type == COLLECTABLE || box.type == EXIT
		|| box.type == HERO || box.type == MUSHROOM)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.ground_img,
			calc_move_x(x, mlx), calc_move_y(y, mlx));
	else if (box.type == WALL)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.wall_img,
			calc_move_x(x, mlx), calc_move_y(y, mlx));
	if (box.type == COLLECTABLE)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.collect_img,
			calc_move_x(x, mlx) + 30, calc_move_y(y, mlx) + 30);
	if (box.type == EXIT && mlx->game.collects > 0)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.exit_close_img,
			calc_move_x(x, mlx), calc_move_y(y, mlx));
	else if (box.type == EXIT)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.exit_open_img,
			calc_move_x(x, mlx), calc_move_y(y, mlx));
	if (box.type == MUSHROOM)
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->game.mushroom_img,
			calc_move_x(x, mlx) + 25, calc_move_y(y, mlx) + 20);
}
