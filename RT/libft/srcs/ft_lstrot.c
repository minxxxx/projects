/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 16:36:52 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/23 11:49:40 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrot(t_list **first, int num)
{
	t_list	*temp;
	t_list	*crawl;

	temp = NULL;
	crawl = NULL;
	if (num > 1)
		if (first != NULL)
		{
			temp = ft_lstpop(first);
			crawl = *first;
			if (crawl != NULL && crawl->next != NULL)
			{
				while (crawl->next != NULL)
					crawl = crawl->next;
			}
			crawl->next = temp;
		}
}
