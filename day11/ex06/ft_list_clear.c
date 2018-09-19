/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:30:48 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/15 13:32:06 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*x;
	t_list	*list;

	list = *begin_list;
	while (list)
	{
		if (list->next)
			x = list->next;
		else
			x = 0;
		free(list);
		list = x;
	}
}
