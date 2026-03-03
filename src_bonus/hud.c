/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hud(t_mlx *mlx)
{
	if (mlx->game.collects && !mlx->game.hero.completed)
	{
		mlx->hud = ft_strf("Cabbages %d", mlx->game.collects);
		mlx_string_put(mlx->init, mlx->win, 20, 30, 0xFFFFFF, mlx->hud);
	}
	else if (!mlx->game.hero.completed)
	{
		mlx->hud = ft_strf("Cabbages %d FIND EXIT!", mlx->game.collects);
		mlx_string_put(mlx->init, mlx->win, 20, 30, 0x00FF00, mlx->hud);
	}
	else if (mlx->hud_flash > 50)
	{
		mlx->hud = ft_strdup("Press R to restart or Enter to change level");
		mlx_string_put(mlx->init, mlx->win, 20, 30, 0xFFFF00, mlx->hud);
		mlx->hud_flash++;
		if (mlx->hud_flash > 150)
			mlx->hud_flash = 0;
	}
	else
		mlx->hud_flash++;
	mlx->hud = ft_free(mlx->hud);
	mlx->hud = ft_strf("Moves %d", mlx->game.moves);
	mlx_string_put(mlx->init, mlx->win, 20, 50, 0xFFFFFF, mlx->hud);
	mlx->hud = ft_free(mlx->hud);
}
