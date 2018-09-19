/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:50 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:45:52 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_front(t_list **l, void const *c, size_t s)
{
	t_list	*list;
	t_list	*new;

	list = *l;
	if (list)
	{
		new = ft_lstnew(c, s);
		new->next = list;
		*l = new;
	}
	else
		*l = ft_lstnew(c, s);
}
