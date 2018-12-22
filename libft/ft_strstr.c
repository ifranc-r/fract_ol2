/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:25:10 by ifranc-r          #+#    #+#             */
/*   Updated: 2014/11/23 22:34:51 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	j;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		j = 0;
		if (*s1 == s2[j])
		{
			while (*(s1 + j) == s2[j] && *(s1 + j) && s2[j])
				j++;
			if (!s2[j])
				return ((char*)s1);
			else if (!*(s1 + j))
				return (NULL);
		}
		s1++;
	}
	return (NULL);
}
