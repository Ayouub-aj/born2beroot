/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	check_move(int key, t_mlx *mlx)
{
	t_bool	moved;

	moved = FALSE;
	if (key == KEY_UP || key == KEY_W)
		moved = move(mlx, mlx->game.hero.box->up);
	else if (key == KEY_DOWN || key == KEY_S)
		moved = move(mlx, mlx->game.hero.box->down);
	else if (key == KEY_LEFT || key == KEY_A)
		moved = move(mlx, mlx->game.hero.box->left);
	else if (key == KEY_RIGHT || key == KEY_D)
		moved = move(mlx, mlx->game.hero.box->right);
	return (moved);
}

int	key_hook(int key, t_mlx *mlx)
{
	t_bool	moved;

	if (key == KEY_ESC)
		close_game();
	moved = check_move(key, mlx);
	if (moved && !mlx->game.hero.completed)
		ft_printf("%d\n", ++mlx->game.moves);
	return (0);
}
