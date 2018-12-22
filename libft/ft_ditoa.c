/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:38:29 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/21 20:10:49 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_d_getn(double n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n > 1 || n < -1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_ditoa(double n, int c)
{
	int		nb;
	char	*s;
	int		i;

	i = 1;
	n < 0 ? i = -1 : 0;
	nb = ft_d_getn(n);
	s = ft_strnew(c + 3);
	(int)n != 0 ? s = ft_itoa((int)n) : 0;
	(int)n == 0 && n < 0 ? s[0] = '-' : 0;
	(int)n == 0 && n < 0 ? s[1] = '0' : 0;
	(int)n == 0 && n < 0 ? ++nb : 0;
	(int)n == 0 && n > 0 ? s[0] = '0' : 0;
	(int)n == 0 && n > 0 ? ++nb : 0;
	s[nb] = '.';
	while (c != 0)
	{
		n -= (int)n;
		n *= 10;
		s[++nb] = ((int)n * i) + '0';
		--c;
	}
	s[nb] = '\0';
	return (s);
}
