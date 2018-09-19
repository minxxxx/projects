/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_small_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:57:37 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 16:57:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	compatable_small_block(t_small_list *small, size_t size)
{
	if (small->used)
		return (0);
	if (small->next)
	{
		if ((size_t)small->next < size && size > (size_t)(small->next +
				SMALL_TOLERANCE))
			return (small->used = 1);
	}
	else
	{
		small->next = size + sizeof(t_small_list);
		small->used = 1;
		small = (t_small_list *)((short)small->next + (long)small);
		small->used = 0;
		small->next = 0;
		return (1);
	}
	return (0);
}

void	*scan_small_block(t_block_zone *block, size_t size)
{
	t_small_list	*small;
	size_t			distance;

	distance = sizeof(t_block_zone) + size + SMALL_TOLERANCE;
	small = (t_small_list *)((long)block + sizeof(t_block_zone) + 1);
	while (distance < (size_t)block->ps.size)
	{
		pthread_mutex_lock(&g_small_lock);
		if (compatable_small_block(small, size))
		{
			pthread_mutex_unlock(&g_small_lock);
			return ((void *)((long)small + (long)sizeof(t_small_list)));
		}
		pthread_mutex_unlock(&g_small_lock);
		distance += (short)small->next;
		small = (t_small_list *)((short)small->next + (long)small);
	}
	return (NULL);
}
