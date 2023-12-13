/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/13 12:49:11 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700

int		ft_count_line(int	fd)
{
	int		i;
	int		rd;
	int		cpt;
	char	*c;

	i = 0;
	cpt = 1;
	while (c[0] && c[0] != '\n')
	{
		rd = read(fd, c, 1);
		if (rd < 1)
			break ;
		if (c[0] == '\n')
			cpt += 1;
		i++;
	}
	return (cpt);
}

char	**ft_read_map(char *fd, int size)
{
	int 	file;
	int		i;
	int		rd;
	char	**map;

	file = open(fd, O_RDONLY);
	size = ft_count_line(file);
	map = malloc(sizeof(char) * size);
	while (map != NULL && i <= INT_MAX)
	{
		map[i] = get_next_line(i);
		i++;
	}
	close(i);
	return (map);
}
char	**ft_parsing_map(char **map)
{
	int	i;
	int	j;
	char	**temp;
	t_map **parsed_map;

	i = 0;
	while (map[i])
	{
		j = 0;
		temp[i] = ft_split(map[i], 32);
		while (temp[j])
		{
			map[j] = ft_atoi(temp[j]);
			j++;
		}
		i++;
	}
	parsed_map = ft_calloc(sizeof(char), i);
	if (!parsed_map)
		return (NULL);
	ft_map_color(parsed_map, map);
	return (parsed_map);
}

char	ft_map_height_color(t_map *parsed_map, char **map)
{
	while (parsed_map->y < map)
	{

	}
	0x00FF0000;
}

char	ft_print_line(int x, int y)
{
	int	x1;
	int	x2;
	int	dx;
	int	y1;
	int	y2;
	int	dy;
	int	coef;
	
	while (x1 <= x2)
	{
		
		mlx_pixel_put(x1, y1);

	}
}

int	main(void)
{
	void	*mlx_ptr;
    void	*win_ptr;

    mlx_ptr = mlx_init();	
    win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}