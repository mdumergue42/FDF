/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/18 19:03:14 by madumerg         ###   ########.fr       */
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
	c = 0;
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

char	**ft_read_map(char *fd)
{
	int 	file;
	int		i;
	int 	size;
	char	**map;

	file = open(fd, O_RDONLY);
	size = ft_count_line(file);
	close(file);
	file = open(fd, O_RDONLY);
	map = malloc(sizeof(char) * size);
	while (map != NULL && i <= INT_MAX)
	{
		map[i] = get_next_line(i);
		i++;
	}
	close(i);
	return (map);
}
t_map	ft_height_color(char *map)
{
	int		z;
	t_map	parsed_map;

	map = ft_calloc(sizeof(t_map), 1);
	while (map[z])
	{
		map[z] = ft_atoi(map);
		parsed_map = map[z];
		z++;
	}
	
}

t_map	**ft_lavoisier(char **map)
{
	t_map	**parsed_map;
	int		z;
	int		x;
	char	**temp;

	z = 0;
	while (map[z])
	{
		temp = ft_split(map[z], ' ');
		x = 0;
		while (temp[x])
		{
			parsed_map[z][x] = ft_height_color(temp[x]);
			x++;
		}
		z++;
	}
	return ();
}

t_map	**ft_parsing_map(char *file_name)
{
	int		file;
	int		i;
	char	**map;
	t_map	**parsed_map;

	if (!file_name)
		map = ft_read_map(file_name);
	parsed_map = ft_lavoisier(map);
	return (parsed_map);
}

/*char	**ft_valid_map(char *map)
{
	char	*line;
	int		fd;

	if (fd < 0)
		return (NULL);
	if (*line == ' ' && *line + 1 == ' ')
		return (NULL);
}*/

/*t_map	*ft_map_height_color(char **map)
{

}*/

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

	vars.mlx = mlx_init();	
	
	vars.win = mlx_new_window(vars.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	
	//mlx_pixel_put(vars.mlx, vars.win, 10, 10, 0x00FFFFFF);
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
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