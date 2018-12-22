/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:17:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/30 18:09:45 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nbr, int power)
{
	int		tmp;

	if (power == 0 || power == 1 / 2)
		return (1);
	if (power > 0)
	{
		while (power-- == 1)
			tmp = nbr * nbr;
	}
	if (power < 0)
	{
		while (power++ == -1)
			tmp = nbr * nbr;
	}
	return (nbr);
}
