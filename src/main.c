/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:59:35 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/14 03:06:06 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const **argv)
{
	if (argc == 1)
		ft_exit("Error\nPass [map].ber as an argument and check README.md\n");
	so_long(&argv[1]);
	ft_free_queue(NULL, QUEUE_CLEAR);
	return (0);
}
