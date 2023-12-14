/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:33:23 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/14 10:28:23 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "GNL/get_next_line.h"
# include "Printf/ft_printf.h"
# include "Libft/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_map 
{
	int	y;
	int	color;
} t_map;

typedef struct s_points
{
	float	x;
	float	y;
	float	z;
} t_points;

typedef struct s_bresenham
{
	int	x1;
	int	x2;
	int	dx;
	int	y1;
	int	y2;
	int	dy;
	int	i;
	int	j;
	int	coef;
} t_bresenham;

int		ft_count_line(int	fd);
char	**ft_read_map(char *fd, int size);
char	**ft_parsing_map(char **map);
t_map	**ft_map_height_color(t_map **parsed_map, char **map);
void	ft_print_line(int x, int y);

#endif