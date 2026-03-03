/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_chars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	parse_map_count_char(char c, t_countchars *count)
{
	if (c == COLLECTABLE)
		count->c++;
	else if (c == EXIT)
		count->e++;
	else if (c == HERO)
		count->p++;
}

void	parse_map_check_chars(char **ss)
{
	int				i;
	int				j;
	t_countchars	count;

	count.c = 0;
	count.e = 0;
	count.p = 0;
	i = 0;
	while (ss[i])
	{
		j = 0;
		while (ss[i][j])
		{
			if (!ft_strchr("01CEPS", ss[i][j]))
				ft_exit(ft_strf("Error\nInvalid character in map: %c\n",
						ss[i][j]));
			parse_map_count_char(ss[i][j], &count);
			j++;
		}
		i++;
	}
	if (count.c == 0 || count.e == 0 || count.p != 1)
		ft_exit("Error\nIncorrect amount of C, E or P chars in a map\n");
}
