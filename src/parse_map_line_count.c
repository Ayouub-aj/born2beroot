/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_line_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_map_line_count(const char *map)
{
	int		lines;
	int		fd;
	int		r;
	char	c;
	t_bool	nl;

	fd = parse_map_open_file(map);
	lines = 1;
	nl = FALSE;
	while (TRUE)
	{
		r = read(fd, &c, 1);
		if (nl && r > 0)
			lines++;
		nl = FALSE;
		if (r == 0)
			break ;
		if (r < 0)
			ft_exit(ft_strf("Error\nCould not read file: %s\n", map));
		if (c == '\n')
			nl = TRUE;
	}
	close(fd);
	return (lines);
}
