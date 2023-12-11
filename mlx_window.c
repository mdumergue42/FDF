/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:45:09 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/11 13:04:42 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "GNL/get_next_line.h"
#include "Printf/ft_printf.h"
#include "Libft/libft.h"

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
	cpt = 0;
	while (c[0] && c[0] != '\n')
	{
		rd = read(fd, c, 1);
		if (rd < 1)
			break ;
		if (c[0] == '\n' || (c[0] == '\n' && c[0] == '\0'))
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
	char	**result;

	file = open(fd, O_RDONLY);
	size = ft_count_line(file);
	result = malloc(sizeof(char) * size)
	while (result != NULL && i <= INT_MAX)
	{
		result[i] = get_next_line(i);
		i++;
	}
	close(i);
}
char	**ft_split_line_map(char *line)
{
	char	*line;


}

ft_split(result);
ft_itoa(file);

