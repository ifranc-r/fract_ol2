/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 15:00:53 by ifranc-r          #+#    #+#             */
/*   Updated: 2014/11/23 22:39:09 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n && *s2 && s1[i])
	{
		j = 0;
		while (i + j < n && s1[i + j] == s2[j] && s1[i + j] && s2[j])
			j++;
		if (!s1[i + j] && s2[j])
			return (NULL);
		if (!s2[j])
			return ((char *)(s1 + i));
		i++;
	}
	if (!*s2 && s1)
		return ((char *)s1);
	else
		return (NULL);
}
