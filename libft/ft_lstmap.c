/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 21:50:36 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/01/26 11:10:37 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = NULL;
	tmp = (*f)(lst);
	tmp2 = tmp;
	while (lst->next)
	{
		tmp->next = (*f)(lst->next);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (tmp2);
}
