/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:50:14 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/29 15:50:53 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrealloc(char **str, char *addtostr)
{
	char *str_realloc;

	if (!(str_realloc = ft_strjoin(*str, addtostr)))
		return (0);
	free(*str);
	*str = str_realloc;
	return (1);
}
