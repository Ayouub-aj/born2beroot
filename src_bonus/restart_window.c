/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_image(mlx->init, mlx->bgr_img->ptr);
	mlx->bgr_img = ft_free(mlx->bgr_img);
	mlx_destroy_image(mlx->init, mlx->game.flash_img->ptr);
	mlx->game.flash_img = ft_free(mlx->game.flash_img);
	mlx_destroy_image(mlx->init, mlx->shade->ptr);
	mlx->shade = ft_free(mlx->shade);
	create_window(mlx);
}
