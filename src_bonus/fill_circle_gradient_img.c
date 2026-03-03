/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_circle_gradient_img.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:06:03 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/13 23:06:14 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	calc_grad(int radius, int x, int y)
{
	float	fy;
	float	fx;
	int		res;

	fy = (float)(radius - ft_abs(radius - y)) / radius;
	fx = (float)(radius - ft_abs(radius - x)) / radius;
	res = (int)(fx * fy * 256);
	return (res * 16777216);
}

void	fill_circle_gradient_img(t_img *img, int radius, unsigned int colour1,
	unsigned int colour2)
{
	int	x;
	int	y;

	y = 0;
	while (y < radius * 2)
	{
		x = 0;
		while (x < radius * 2)
		{
			(void)colour1;
			(void)colour2;
			(void)calc_grad;
			my_mlx_pixel_put(img, x, y, calc_grad(radius, x, y));
			x++;
		}
		y++;
	}
}
