/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_tiny_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:29:23 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 16:29:25 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	compatable_tiny_block(t_tiny_list *tiny, size_t size)
{
	if (tiny->used)
		return (0);
	if (tiny->next)
	{
		if ((size_t)tiny->next < size && size > (size_t)(tiny->next +
				TINY_TOLERANCE))
			return (tiny->used = 1);
	}
	else
	{
		tiny->next = size + sizeof(t_tiny_list);
		tiny->used = 1;
		tiny = (t_tiny_list *)((short)tiny->next + (long)tiny);
		tiny->used = 0;
		tiny->next = 0;
		return (1);
	}
	return (0);
}

void	*scan_tiny_block(t_block_zone *block, size_t size)
{
	t_tiny_list		*tiny;
	size_t			distance;

	distance = sizeof(t_block_zone) + size + TINY_TOLERANCE;
	tiny = (t_tiny_list *)((long)block + sizeof(t_block_zone) + 1);
	while (distance < (size_t)block->ps.size)
	{
		pthread_mutex_lock(&g_tiny_lock);
		if (compatable_tiny_block(tiny, size))
		{
			pthread_mutex_unlock(&g_tiny_lock);
			return ((void *)((long)tiny + (long)sizeof(t_tiny_list)));
		}
		pthread_mutex_unlock(&g_tiny_lock);
		distance += (short)tiny->next;
		tiny = (t_tiny_list *)((short)tiny->next + (long)tiny);
	}
	return (NULL);
}
