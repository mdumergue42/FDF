/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:34:51 by madumerg          #+#    #+#             */
/*   Updated: 2023/11/28 12:15:59 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
size_t	ft_strlen(const char *str);
int		ft_putnbr_uns_int(unsigned int n);
int		ft_putnbr_hexa_low(size_t n);
int		ft_putnbr_hexa_upp(unsigned int n);
int		ft_print_ptr(void *ptr);

#endif
