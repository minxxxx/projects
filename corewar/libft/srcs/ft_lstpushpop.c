/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 08:00:23 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/29 17:15:34 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushpop(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*a)
	{
		temp = ft_lstpop(a);
		if (temp != NULL)
			ft_lstpush(b, temp);
	}
}
