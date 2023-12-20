/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madumerg <madumerg@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:37:39 by madumerg          #+#    #+#             */
/*   Updated: 2023/12/20 15:46:19 by madumerg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base(char *base)
{
	char	*x;
	char	*X;

	x = "0123456789abcdef";
	X = "0123456789ABCDEF";


}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	r;
	int	s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 16 + ft_base(str) - '0';
		i++;
	}
	return (r *= s);
}