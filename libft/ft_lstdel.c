/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:59:39 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/26 11:12:00 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*alst)->next;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		ft_lstdelone(&tmp2, (*del));
	}
	ft_lstdelone(alst, (*del));
}
