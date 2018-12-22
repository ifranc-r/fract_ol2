/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 23:07:20 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/29 00:03:05 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freestrjoin(char *s1, char *s2, int s)
{
	char		*str;
	int			x;
	int			y;

	x = s1 != NULL ? ft_strlen(s1) : 0;
	y = s2 != NULL ? ft_strlen(s2) : 0;
	str = (char *)ft_memalloc(sizeof(char) * (x + y + 1));
	x = 0;
	while (s1 && s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	if (s1 && (s == 1 || s == 3))
		free(s1);
	y = 0;
	while (s2 && s2[y])
	{
		str[x + y] = s2[y];
		y++;
	}
	if (s2 && (s == 2 || s == 3))
		free(s2);
	return (str);
}
