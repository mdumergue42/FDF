/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 06:33:23 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/12 12:41:30 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBMLX_H
# define LIBMLX_X

# include "minilibx-linux/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "GNL/get_next_line.h"
# include "Printf/ft_printf.h"
# include "Libft/libft.h"

typedef struct s_map 
{
	int	z;
	int	color;
} t_map;


#endif