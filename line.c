/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 09:26:27 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/23 11:05:40 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// C program for DDA line generation 

#include "fdf.h"
#include <math.h> 
#include <stdio.h> 
/*// Function for finding absolute value 
int abs(int n) { return ((n > 0) ? n : (n * (-1))); } 

// DDA Function for line generation 
void ft_DDA(int X0, int Y0, int X1, int Y1, t_vars vars) 
{
	// calculate dx & dy 
	int dx = X1 - X0; 
	int dy = Y1 - Y0; 

	// calculate steps required for generating pixels 
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

	// calculate increment in x & y for each steps 
	float Xinc = dx / (float)steps; 
	float Yinc = dy / (float)steps; 

	// Put pixel for each step 
	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++) { 
		mlx_pixel_put(vars.mlx, vars.win, X, Y, ft_atoi_base("FF0000", "0123456789ABCDEF"));
		// put pixel at (X,Y) 
		X += Xinc; // increment in x at each step 
		Y += Yinc; // increment in y at each step 
		//delay(100); // for visualization of line- 
					// generation step by step 
	} 
} */

// Driver program 

void drawline(t_vars vars, t_bresenham math)  
{
	math.dx = math.x2 - math.x1;
	math.dy = math.y2 - math.y1;
	math.x = math.x1;
	math.y = math.y1;
	math.m = 2 * math.dy - math.dx;

	while(math.x < math.x2)  
	{  
		if(math.m >= 0)  
		{  
			mlx_pixel_put(vars.mlx, vars.win, math.x, math.y, ft_atoi_base("FF0000", "0123456789ABCDEF")); 
			math.y = math.y + 1;
			math.m = math.m + 2 * math.dy - 2 * math.dx;
		}  
		else  
		{  
			mlx_pixel_put(vars.mlx, vars.win, math.x, math.y, ft_atoi_base("FF0000", "0123456789ABCDEF"));
			math.m = math.m + 2 * math.dy;  
			math.x = math.x + 1;  
		}
	} 
}


# define WINDOW_WIDTH 700
# define WINDOW_HEIGHT 400

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
	t_bresenham	math = {2, 2, 14, 16};

	vars.mlx = mlx_init();	
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	drawline(vars, math);
	mlx_loop(vars.mlx);
	free(vars.mlx);
}
