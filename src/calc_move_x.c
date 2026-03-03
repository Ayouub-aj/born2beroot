/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_move_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calc_move_x(int x, t_mlx *mlx)
{
	return (((x - mlx->game.hero.box->pos.x) * IMG + mlx->win_w / 2 - 50)
		+ (mlx->game.hero.box->pos.x - mlx->game.size.x / 2) * mlx->win_w
		/ mlx->game.size.x / 3);
}
