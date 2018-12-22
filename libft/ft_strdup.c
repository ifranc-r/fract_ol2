/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 09:08:52 by ifranc-r          #+#    #+#             */
/*   Updated: 2015/07/23 12:38:51 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*st;

	st = ft_memalloc(ft_strlen(s1) + 1);
	if (st == NULL)
		return (NULL);
	st = ft_strcpy(st, s1);
	return (st);
}
