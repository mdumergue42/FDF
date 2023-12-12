/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/12 12:41:29 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700


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
	char	**temp;
	t_map t;

	i = 0;
	while (map[i])
	{
		temp += ft_split(map, 32);
		while (temp[i])
		{
			temp [i] = ft_atoi(map[i]);
			i++;
		}
		i++;
	}
	return (map);
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

ft_split(map);
ft_itoa(file);

