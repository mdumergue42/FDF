/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:23:25 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/23 09:51:53 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_sign_of_increment(int x1, int x2, int y1, int y2)
{
	int			sign_x;
	int			sign_y;

	if (x1 < x2)
	{
		sign_x += 1;
		return (sign_x);
	}
	else
	{
		sign_x -= -1;
		return (sign_x);
	}
	if (y1 < y2)
	{
		sign_y += 1;
		return (sign_y);
	}
	else
	{
		sign_y -= -1;
		return (sign_y);
	}
}

void	ft_bresenham(t_vars vars, t_bresenham math)
{
	t_map	map;
	int		err;
	int		i;

	math.dx = abs(math.x2 - math.x1);
	math.dy = abs(math.y2 - math.y1);
	ft_sign_of_increment(math.x1, math.x2, math.y1, math.y2);
	math.x = math.x1;
	math.y = math.y1;
	if (math.dx > math.dy)
	{
		err = math.dx / 2;
		i = 0;
		while (i < math.dx)
		{
			math.x += math.xi;
			err += math.dy;
			if (err > math.dx)
			{
				err -= math.dx;
				math.y += math.yi;
			}
			mlx_pixel_put(vars.mlx, vars.win, math.x, math.y, map.color);
			i++;
		}
	}
	else
	{
		err = math.dy / 2;
		i = 0;
		while (i < math.dy)
		{
			math.y += math.yi;
			err += math.dx;
			if (err > math.dy)
			{
				err -= math.dy;
				math.x += math.xi;
			}
			mlx_pixel_put(vars.mlx, vars.win, math.x, math.y, map.color);
			i++;
		}
	}
	//mlx_pixel_put(vars.mlx, vars.win, math.x1, math.y1, map.color);
	//mlx_pixel_put(vars.mlx, vars.win, math.x2, math.y2, map.color);
}

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_bresenham	math = {2, 20, 10, 70};

	vars.mlx = mlx_init();	
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	ft_bresenham(vars, math);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}







/*dx = x1 - x0
    dy = y1 - y0
    xi = 1
    if dx < 0
        xi = -1
        dx = -dx
    end if
    D = (2 * dx) - dy
    x = x0

    for y from y0 to y1
        plot(x, y)
        if D > 0
            x = x + xi
            D = D + (2 * (dx - dy))
        else
            D = D + 2*dx
        end if*/