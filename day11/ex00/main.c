/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 10:01:55 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/14 10:17:16 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

int	main(void)
{
	t_list *list;

	list = ft_create_elem("1\n");
	list->next = ft_create_elem("2\n");
	list->next->next = ft_create_elem("3\n");
	printf("Wassop yol\n");
	while (list)
	{
		printf(list->data);
		list = list->next;
	}
	return (0);
}
