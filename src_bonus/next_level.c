/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	next_level(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->game.size.y)
		mlx->game.map[i] = ft_free(mlx->game.map[i]);
	mlx->game.map = ft_free(mlx->game.map);
	if (!mlx->maps[++mlx->map_index])
	{
		ft_printf("This was the last map... Starting over!\n");
		mlx->map_index = 0;
	}
	parse_map(mlx->maps[mlx->map_index], mlx);
	prepare_imgs(mlx);
	prepare_settings(mlx);
	reset_game(mlx);
	ft_printf("Playing: %s\n", mlx->maps[mlx->map_index]);
}
