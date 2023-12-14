/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/14 15:20:08 by madumerg         ###   ########.fr       */
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
	ft_map_height_color(parsed_map, map);
	return (parsed_map);
}

t_map	**ft_map_height_color(t_map **parsed_map, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			k = 0;
			if (map[i][j] == ft_isdigit)
			{
				while (map[i][j] != ',')
				{
						
				}
			}
		}
		i++;
	}
	return (parsed_map);
	
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




dx = x1 - x0
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
        end if