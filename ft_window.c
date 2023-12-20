/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/20 15:49:42 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 700

int		ft_count_line(int fd)
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

int	ft_error(void)
{
	ft_printf("Error\n");
	return (-1);
}

t_map	ft_height_color(char *map)
{
	int		z;
	t_map	parsed_map;

	z = 0;
	//parsed_map = ft_calloc(sizeof(t_map), 1);
//	if (!parsed_map)
//		return (NULL);ntm
	parsed_map.y = ft_atoi(map);
	while (map[z] && map[z] != ',')
		z++;
	z++;
	while (map[z])
	{
		parsed_map.color = ft_atoi_base(&map[z + 2]);
		z++;
	}
	return (parsed_map);
}
//z+2 pour skip le 0x
//ce qu'on envoie dans height color
//10
//10,0x00ff00

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
	return (parsed_map);
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
	return (tab);
	//mlx_pixel_put(vars.mlx, vars.win, 10, 10, 0x00FFFFFF);
	//mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	//mlx_loop(vars.mlx);
	//free(vars.mlx);
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