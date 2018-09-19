/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tiny_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:22:19 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 09:22:20 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	divide_tiny_block(t_tiny_list *tiny, size_t size)
{
	t_tiny_list		*new_tiny;

	ERROR_RETURN(size > tiny->next + sizeof(t_tiny_list) + TINY_TOLERANCE);
	pthread_mutex_lock(&g_tiny_lock);
	new_tiny = (tiny + size) + sizeof(t_tiny_list);
	new_tiny->used = 0;
	new_tiny->next = tiny->next - (size + sizeof(t_tiny_list));
	tiny->next = size + sizeof(t_tiny_list);
	pthread_mutex_unlock(&g_tiny_lock);
	return (1);
}

char	merge_tiny_block(t_tiny_list *tiny)
{
	t_tiny_list		*old_tiny;

	old_tiny = tiny + tiny->next + sizeof(t_tiny_list);
	ERROR_RETURN(tiny->next + old_tiny->next + sizeof(t_tiny_list) >
		TINY_MAX || old_tiny->used);
	pthread_mutex_lock(&g_tiny_lock);
	tiny->next += old_tiny->next + sizeof(t_tiny_list);
	pthread_mutex_unlock(&g_tiny_lock);
	return (1);
}

/*
** Doesn't include error hanlding for page overflow
*/

char	realloc_tiny_block(void *ptr, size_t size)
{
	t_tiny_list		*tiny;

	tiny = (t_tiny_list *)(ptr - sizeof(t_tiny_list));
	if (size < (size_t)tiny->next && size < TINY_MAX)
	{
		SUCCESS_RETURN(size > (size_t)tiny->next + TINY_TOLERANCE);
		SUCCESS_RETURN(divide_tiny_block(tiny, size));
	}
	else if (size > tiny->next)
		SUCCESS_RETURN(merge_tiny_block(tiny));
	return (0);
}
