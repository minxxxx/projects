/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 13:41:39 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/22 15:27:17 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **list, t_list *node)
{
	t_list	*trav;

	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	trav = *list;
	while (trav->next != NULL)
		trav = trav->next;
	trav->next = node;
}
