/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:34:15 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 00:48:36 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = NULL;
	while (*alst)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		free(*alst);
		(*alst) = NULL;
		*alst = tmp->next;
	}
}
