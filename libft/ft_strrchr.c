/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 02:00:45 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/28 21:46:05 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	if (*s == '\0')
		return ((c == 0) ? (char *)s : NULL);
	last = ft_strrchr(s + 1, c);
	if (!last && *s == (char)c)
		return ((char *)s);
	else
		return (last);
}
