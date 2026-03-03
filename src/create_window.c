/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_mlx *mlx)
{
	mlx->win = ft_nn(mlx_new_window(mlx->init, mlx->win_w, mlx->win_h,
				"so_long"), "Error\nmlx_new_window() is null\n");
	mlx->bgr_img = new_image(mlx, mlx->win_w, mlx->win_h);
	fill_square_img(mlx->bgr_img, mlx->win_w, mlx->win_h, 0x000000);
	mlx_loop_hook(mlx->init, render_next_frame, mlx);
	mlx_hook(mlx->win, 2, (1L << 0), key_hook, mlx);
	mlx_hook(mlx->win, 17, 0, close_game, mlx);
	mlx_loop(mlx->init);
}
