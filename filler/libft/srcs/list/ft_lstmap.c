/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:33:17 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:14:03 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*new_lst;
	t_list	*last_node;

	list = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst)->content, (*f)(lst)->content_size);
		if (list)
			last_node->next = new_lst;
		else
			list = new_lst;
		last_node = new_lst;
		lst = lst->next;
	}
	return (list);
}
