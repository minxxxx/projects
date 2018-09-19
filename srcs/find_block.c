/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:44:38 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 07:44:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char			is_in_block(t_block_zone *block, void *ptr)
{
	if ((void *)block < ptr && ptr < (void *)((long)block +
			(long)block->ps.size))
		return (1);
	return (0);
}

t_block_data	find_in_tiny_block(void *ptr)
{
	t_block_data	block_data;

	block_data.block = g_zones.tiny_block;
	block_data.block_type = TINY_BLOCK;
	while (block_data.block)
	{
		if (is_in_block(block_data.block, ptr))
			return (block_data);
		block_data.block = block_data.block->next;
	}
	block_data.block = NULL;
	return (block_data);
}

t_block_data	find_in_small_block(void *ptr)
{
	t_block_data	block_data;

	block_data.block = g_zones.small_block;
	block_data.block_type = SMALL_BLOCK;
	while (block_data.block)
	{
		if (is_in_block(block_data.block, ptr))
			return (block_data);
		block_data.block = block_data.block->next;
	}
	block_data.block = NULL;
	return (block_data);
}

t_block_data	find_in_large_block(void *ptr)
{
	t_block_data	block_data;

	block_data.block = g_zones.large_block;
	block_data.block_type = LARGE_BLOCK;
	while (block_data.block)
	{
		if (is_in_block(block_data.block, ptr))
			return (block_data);
		block_data.block = block_data.block->next;
	}
	block_data.block = NULL;
	return (block_data);
}

t_block_data	find_block(void *ptr)
{
	t_block_data	block_data;

	block_data = find_in_tiny_block(ptr);
	if (block_data.block)
		return (block_data);
	block_data = find_in_small_block(ptr);
	if (block_data.block)
		return (block_data);
	block_data = find_in_large_block(ptr);
	if (block_data.block)
		return (block_data);
	block_data.block = NO_BLOCK;
	return (block_data);
}
