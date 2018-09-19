/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_large_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:29:04 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 09:29:06 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
** This can create fragementation so be careful. Look here when debugging
** This can be used to create the defragor
*/

char	resize_large_block(t_block_zone *block, t_page_size ps, size_t size)
{
	pthread_mutex_lock(&g_large_lock);
	if (allocate_page(block, ps.size))
	{
		block->ps = ps;
		block->active_members = size;
		pthread_mutex_unlock(&g_large_lock);
		return (1);
	}
	pthread_mutex_unlock(&g_large_lock);
	return (0);
}

/*
** May have not copied all the info over, this will have to be tested!
*/

void	*realloc_large_block(t_block_zone *block, size_t size)
{
	t_page_size		ps;
	t_block_zone	*parent_block;
	t_block_zone	*new_block;

	ps = round_to_pagesize(size + sizeof(t_block_zone));
	if (ps.pages == block->ps.pages || resize_large_block(block, ps, size))
		return (block);
	pthread_mutex_lock(&g_large_lock);
	parent_block = g_zones.large_block;
	while (parent_block->next && parent_block->next != block)
		parent_block = parent_block->next;
	if ((new_block = allocate_page(NULL, ps.size)) == NULL)
	{
		pthread_mutex_unlock(&g_large_lock);
		return (NULL);
	}
	new_block->next = block->next;
	new_block->ps = ps;
	new_block->active_members = size;
	parent_block->next = new_block;
	ft_memmove((void *)((long)new_block + sizeof(t_block_zone)),
		(void *)((long)block + sizeof(t_block_zone)), block->active_members);
	munmap(block, block->ps.size);
	pthread_mutex_unlock(&g_large_lock);
	return (NULL);
}
