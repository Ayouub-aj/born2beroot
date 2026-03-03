/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(const char *map, t_mlx *mlx)
{
	char	**ss;

	parse_map_ber_ext(map);
	mlx->game.size.y = parse_map_line_count(map);
	ss = parse_map_get_strings(map, mlx->game.size.y);
	mlx->game.size.x = parse_map_line_len(ss);
	parse_map_check_walls(ss, mlx->game.size.x, mlx->game.size.y);
	parse_map_check_chars(ss);
	mlx->game.collects = 0;
	mlx->game.map = parse_map_create_boxes(ss, mlx->game.size.x,
			mlx->game.size.y, mlx);
	ss = ft_free_strings(ss);
	parse_map_connect_boxes(mlx->game.size.x, mlx->game.size.y, mlx);
}
