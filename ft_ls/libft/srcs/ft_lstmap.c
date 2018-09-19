/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:19:34 by acazuc            #+#    #+#             */
/*   Updated: 2015/11/25 15:51:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_list_item;

	if (lst)
	{
		new_list = f(lst);
		new_list_item = new_list;
		lst = lst->next;
		while (lst)
		{
			new_list_item->next = f(lst);
			new_list_item = new_list_item->next;
			lst = lst->next;
		}
		return (new_list);
	}
	return (NULL);
}
