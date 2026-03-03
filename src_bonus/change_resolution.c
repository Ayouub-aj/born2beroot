/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_resolution(int key, t_mlx *mlx)
{
	if (key == KEY_1 && mlx->win_w != 640)
	{
		mlx->win_w = 640;
		mlx->win_h = 480;
	}
	else if (key == KEY_2 && mlx->win_w != 800)
	{
		mlx->win_w = 800;
		mlx->win_h = 600;
	}
	else if (key == KEY_3 && mlx->win_w != 1280)
	{
		mlx->win_w = 1280;
		mlx->win_h = 720;
	}
	else if (key == KEY_4 && mlx->win_w != 1920)
	{
		mlx->win_w = 1920;
		mlx->win_h = 1080;
	}
	restart_window(mlx);
}
