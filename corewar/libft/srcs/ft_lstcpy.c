/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 13:13:39 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/15 17:00:44 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_opt(t_list *src, t_list *dst)
{
	while (src && dst)
	{
		dst->op_pos = src->op_pos;
		dst = dst->next;
		src = src->next;
	}
}

t_list		*ft_lstcpy(t_list *start_src)
{
	t_list	*trav;
	t_list	*new;
	int		*num;

	new = NULL;
	if (start_src)
	{
		trav = start_src;
		num = (int*)malloc(sizeof(int));
		*num = *(int*)trav->data;
		new = ft_lstnew(num);
		trav = trav->next;
		while (trav)
		{
			num = (int*)malloc(sizeof(int));
			*num = *(int*)trav->data;
			ft_lstappend(&new, ft_lstnew(num));
			trav = trav->next;
		}
		copy_opt(start_src, new);
	}
	return (new);
}
