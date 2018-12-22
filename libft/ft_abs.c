/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:59:00 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/29 16:01:39 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_abs(int n)
{
	unsigned int n_absolute;

	if (n < 0)
		n_absolute = -n;
	else
		n_absolute = n;
	return (n_absolute);
}
