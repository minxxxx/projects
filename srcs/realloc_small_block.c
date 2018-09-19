/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_small_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:28:57 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 09:28:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	divide_small_block(t_small_list *small, size_t size)
{
	t_small_list		*new_small;

	ERROR_RETURN(size > small->next + sizeof(t_small_list) + SMALL_TOLERANCE);
	pthread_mutex_lock(&g_small_lock);
	new_small = (small + size) + sizeof(t_small_list);
	new_small->used = 0;
	new_small->next = small->next - (size + sizeof(t_small_list));
	small->next = size + sizeof(t_small_list);
	pthread_mutex_unlock(&g_small_lock);
	return (1);
}

char	merge_small_block(t_small_list *small)
{
	t_small_list		*old_small;

	old_small = small + small->next + sizeof(t_small_list);
	ERROR_RETURN(small->next + old_small->next +
		sizeof(t_small_list) > SMALL_MAX || old_small->used);
	pthread_mutex_lock(&g_small_lock);
	small->next += old_small->next + sizeof(t_small_list);
	pthread_mutex_unlock(&g_small_lock);
	return (1);
}

/*
** Doesn't include error hanlding for page overflow
*/

char	realloc_small_block(void *ptr, size_t size)
{
	t_small_list		*small;

	small = (t_small_list *)(ptr - sizeof(t_small_list));
	if (size < (size_t)small->next && size < SMALL_MAX)
	{
		SUCCESS_RETURN(size > (size_t)small->next + SMALL_TOLERANCE);
		SUCCESS_RETURN(divide_small_block(small, size));
	}
	else if (size > small->next)
		SUCCESS_RETURN(merge_small_block(small));
	return (0);
}
