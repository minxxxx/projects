/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 05:20:45 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/27 13:04:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(const char *content, size_t content_size)
{
	t_list	*nl;

	nl = (t_list*)malloc(sizeof(t_list));
	if (!nl)
		return (NULL);
	if (!nl->content)
		nl->content_size = 0;
	else
	{
		nl->content = ft_memalloc(content_size);
		nl->content = ft_memcpy(nl->content, content, content_size);
		nl->content_size = content_size;
	}
	nl->next = NULL;
	return (nl);
}
