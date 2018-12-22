/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 12:00:11 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/23 12:24:09 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*a_s1;
	unsigned char	*a_s2;

	i = 0;
	a_s1 = (unsigned char *)s1;
	a_s2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (a_s1[i] != a_s2[i])
			return (a_s1[i] - a_s2[i]);
		i++;
		n--;
	}
	return (0);
}
