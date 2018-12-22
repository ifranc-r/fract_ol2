/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:28:19 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/23 12:04:11 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*adst;
	const char	*asrc;

	adst = dst;
	asrc = src;
	i = 0;
	while (i < n)
	{
		adst[i] = asrc[i];
		i++;
	}
	return (dst);
}
