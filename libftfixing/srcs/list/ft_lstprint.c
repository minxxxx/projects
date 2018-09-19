/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 04:51:09 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/13 04:51:10 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, void (*print)(void *))
{
	while (lst)
	{
		ft_putstr("\033[033mcontent : \033[0m[");
		if (print)
			(*print)(lst->content);
		else
			ft_putstr(lst->content);
		ft_putstr("]\t\033[035msize : \033[0m[");
		ft_putnbr(lst->content_size);
		ft_putstr("]\n");
		lst = lst->next;
	}
}
