/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_move_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calc_move_y(int y, t_mlx *mlx)
{
	return (((y - mlx->game.hero.box->pos.y) * IMG + mlx->win_h / 2 - 50)
		+ (mlx->game.hero.box->pos.y - mlx->game.size.y / 2) * mlx->win_h
		/ mlx->game.size.y / 3);
}
