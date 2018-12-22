/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:23:23 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/28 21:42:11 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	l;

	a = 0;
	i = 0;
	l = ft_strlen(dst) + ft_strlen(src);
	while (dst[i] != '\0' && i < size)
		i++;
	if (i - size == 0)
		return (i + ft_strlen(src));
	while (src[a] != '\0' && i < size - 1)
	{
		dst[i] = src[a];
		a++;
		i++;
	}
	dst[i] = '\0';
	return (l);
}
