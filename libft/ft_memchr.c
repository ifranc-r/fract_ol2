/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:26:12 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/23 12:26:07 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a_s;
	int				i;

	i = 0;
	a_s = (unsigned char *)s;
	while (n--)
	{
		if (a_s[i] == (unsigned char)c)
			return (char *)(s + i);
		i++;
	}
	return (NULL);
}
