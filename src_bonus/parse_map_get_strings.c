/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_get_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map_get_strings(const char *map, int lines)
{
	int		fd;
	char	**ss;
	char	*s;
	int		i;

	fd = parse_map_open_file(map);
	ss = ft_malloc(sizeof(char *) * lines + 1);
	s = ft_gnl(fd);
	i = 0;
	while (s && ft_strlen(s) > 0)
	{
		ss[i++] = ft_strtrim(s, "\n");
		s = ft_free(s);
		s = ft_gnl(fd);
	}
	s = ft_free(s);
	ss[i] = NULL;
	close(fd);
	return (ss);
}
