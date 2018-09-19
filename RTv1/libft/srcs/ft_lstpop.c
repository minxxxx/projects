/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 13:56:05 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/27 16:40:04 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **first)
{
	t_list	*temp;
	t_list	*crawl;

	temp = *first;
	crawl = *first;
	if (crawl)
	{
		if (crawl->next != NULL)
		{
			crawl = crawl->next;
			*first = crawl;
		}
		else
			*first = NULL;
	}
	temp->next = NULL;
	return (temp);
}
