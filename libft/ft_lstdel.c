/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 11:45:17 by amkhuma           #+#    #+#             */
/*   Updated: 2017/06/18 12:25:52 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*newlist;

	new = *alst;
	while (new)
	{
		newlist = new->next;
		del(new->content, new->content_size);
		free(new);
		new = newlist;
	}
	*alst = NULL;
}
