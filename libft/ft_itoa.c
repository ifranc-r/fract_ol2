/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 11:51:25 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/28 21:53:51 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_compute_nbsize(int nb)
{
	if (nb / 10 == 0)
		return (1);
	return (1 + ft_compute_nbsize(nb / 10));
}

char			*ft_itoa(int n)
{
	size_t	size;
	int		neg;
	char	*nbstr;

	neg = (n < 0) ? 1 : 0;
	size = neg + ft_compute_nbsize(n);
	nbstr = ft_strnew(size);
	if (!nbstr)
		return (NULL);
	if (neg == 1)
		nbstr[0] = '-';
	while (size-- > (size_t)neg)
	{
		nbstr[size] = '0' + (char)((neg) ? (0 - n % 10) : (n % 10));
		n /= 10;
	}
	return (nbstr);
}
