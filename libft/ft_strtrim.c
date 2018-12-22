/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 17:30:26 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/28 21:47:44 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*tmp;
	size_t	x;
	size_t	y;
	size_t	o;

	x = 0;
	o = 0;
	y = ft_strlen(s);
	while ((s[x] == ' ') || (s[x] == '\n') || (s[x] == '\t'))
		x++;
	while (((s[y - 1] == ' ') || (s[y - 1] == '\n') || (s[y - 1] == '\t')) && \
			(x != y))
		y--;
	tmp = (char *)malloc(sizeof(char) * ((y - x) + 1));
	if (!tmp)
		return (NULL);
	while (y - (o + x))
	{
		tmp[o] = s[x + o];
		o++;
	}
	tmp[o] = '\0';
	return (tmp);
}
