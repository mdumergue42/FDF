/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:49:18 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/23 10:07:23 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
	
	t_map	**tab;
	int		x;
	int		z;
	//t_vars	vars;
	//vars.mlx = mlx_init();	
	
	//vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	tab = ft_parsing_map(tab);
	z = 0;
	while (tab[z])
	{
		x = 0;
		while (tab[z][x])
		{
			ft_printf("%s, %d", tab[z][x].color);
			x++;
		}
		z++;
	}
	return (0);
	//mlx_pixel_put(vars.mlx, vars.win, 10, 10, 0x00FFFFFF);
	//mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	//mlx_loop(vars.mlx);
	//free(vars.mlx);
}
