/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 08:05:07 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/28 18:15:53 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	del(void *list, size_t size)
{
	list = "NOTHING";
	size = 2;
}

void	ft_lstdelone(t_list **alst, void(*del)(void *, size_t))
{
	(*del)(&((*alst)->content), (*alst)->content_size);
	free(*alst->content);
	free(*alst->content_size);
	*alst->next = NULL;
}

int		main(void)
{
	t_list **test;
	char string[] = "Hello World";
	size_t size = 5;
	char *str;
	void (*f)(void *,size_t);
	
	(*test)->content = malloc(sizeof(char) * 5)
	(*test)->content = ft_memcpy((*test)->content, string, size);
	(*test)->content_size = size;
	f = &del;
	printf("Before function: %s %zu\n", (*test)->content, (*test)->content_size);
//	ft_lstdelone(test, f);
//	printf("After function: %s %zu\n", (*test)->content, (*test)->content_size);
	return (0);
}
