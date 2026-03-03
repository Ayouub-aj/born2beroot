/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(const char **maps)
{
	t_mlx	*mlx;

	mlx = ft_malloc(sizeof(t_mlx));
	mlx->win_w = 640;
	mlx->win_h = 480;
	parse_map(maps[0], mlx);
	mlx->init = ft_nn(mlx_init(), "Error\nmlx_init() is null\n");
	prepare_imgs(mlx);
	prepare_settings(mlx);
	create_window(mlx);
}
