/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 00:27:39 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/28 21:37:50 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	a_c;

	a_c = c;
	a = 0;
	if (a_c == 0)
		return (char *)(&s[ft_strlen(s)]);
	while (s[a] != '\0')
	{
		if (s[a] == a_c)
			return (char *)(s + a);
		a++;
	}
	return (0);
}
