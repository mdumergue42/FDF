/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:33:23 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/23 10:49:43 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "GNL/get_next_line.h"
# include "PRINTF/ft_printf.h"
# include "Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_vars
{
	void *mlx;
	void *win;
}	t_vars;

typedef struct s_map
{
	int	y;
	int	color;
}	t_map;

typedef struct s_bresenham
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	xi;
	int	yi;
	int m;
}	t_bresenham;

int		ft_count_line(int fd);
char	**ft_read_map(char *fd);
t_map	**ft_parsing_map(char *file_name);
t_map	**ft_map_height_color(t_map **parsed_map, char **map);
void	ft_print_line(t_vars vars, t_bresenham math);

#endif