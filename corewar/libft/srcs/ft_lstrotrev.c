/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:00:10 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 11:49:50 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrotrev(t_list **first, int num)
{
	t_list	*crawl;
	t_list	*temp;

	temp = NULL;
	crawl = NULL;
	if (num > 1)
	{
		if (first != NULL)
		{
			crawl = *first;
			while (crawl->next->next != NULL)
				crawl = crawl->next;
			temp = crawl->next;
			crawl->next = NULL;
			temp->next = *first;
			*first = temp;
		}
	}
}
