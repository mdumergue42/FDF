/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:23:25 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/14 15:20:06 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_sign_of_increment(int x1, int x2, int y1, int y2)
{
	t_bresenham math;
	int	i;
	int	j;
	
	if (x1 < x2)
		i += 1;
	else
		i -= -1;
	if (y1 < y2)
		j += 1;
	else
		j -= -1;
	math.dx = abs(math.x2 - math.x1);
	math.dy = abs(math.y2 - math.y1);
	i = math.dx / 2;
	j = math.dy / 2;
}

void	ft_print_line(int x, int y)
{
	t_bresenham math;
	
	x = math.x1;
	y = math.y1;
	ft_sign_of_increment(math.x1, math.x2, math.y1, math.y2);
	mlx_pixel_put
}
i = dx / abs
j = dy / abs