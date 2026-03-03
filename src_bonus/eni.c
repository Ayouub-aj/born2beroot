/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eni.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*eni(void *ptr)
{
	if (!ptr)
	{
		ft_free_queue(NULL, QUEUE_CLEAR);
		ft_exit("Error\nmlx_xpm_file_to_image() is null\n");
	}
	return (ptr);
}
