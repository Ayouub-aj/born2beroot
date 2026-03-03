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
	{
		mlx->game.hero.left = 1;
		moved = move(mlx, mlx->game.hero.box->left);
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		mlx->game.hero.left = 0;
		moved = move(mlx, mlx->game.hero.box->right);
	}
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4)
		change_resolution(key, mlx);
	return (moved);
}

int	key_hook(int key, t_mlx *mlx)
{
	t_bool	moved;

	if (key == KEY_ESC)
		close_game();
	else if (key == KEY_R)
		reset_game(mlx);
	else if (key == KEY_ENTER || key == KEY_TAB)
		next_level(mlx);
	moved = check_move(key, mlx);
	if (moved && !mlx->game.hero.completed)
		++mlx->game.moves;
	else
		mlx->game.hero.action_frames = 10;
	return (0);
}
