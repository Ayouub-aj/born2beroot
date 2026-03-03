/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	prepare_imgs(t_mlx *mlx)
{
	mlx->game.ground_img = eni(mlx_xpm_file_to_image(mlx->init,
				"sprites/ground.xpm", &mlx->w, &mlx->h));
	mlx->game.wall_img = eni(mlx_xpm_file_to_image(mlx->init,
				"sprites/wall.xpm", &mlx->w, &mlx->h));
	mlx->game.collect_img = eni(mlx_xpm_file_to_image(mlx->init,
				"sprites/collect.xpm", &mlx->w, &mlx->h));
	mlx->game.exit_open_img = eni(mlx_xpm_file_to_image(mlx->init,
				"sprites/exit_1.xpm", &mlx->w, &mlx->h));
	mlx->game.hero.current_img = eni(mlx_xpm_file_to_image(mlx->init,
				"sprites/hero_0.xpm", &mlx->w, &mlx->h));
}
