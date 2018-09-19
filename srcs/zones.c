/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:44:00 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 15:44:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

char	extend_zone(t_block_zone *block, t_page_size page_size)
{
	t_block_zone	*new_block;
	int				*clear;

	if ((new_block = allocate_page(BLOCK_END, page_size.size)) != NULL)
	{
		block->ps.size += page_size.size;
		block->ps.pages += page_size.pages;
	}
	else
	{
		block->next = allocate_page(NULL, page_size.size);
		FATAL_ERROR_RETURN(block->next == NULL);
		new_block = block->next;
		new_block->next = NULL;
		new_block->ps = page_size;
		new_block->active_members = 0;
		clear = (int *)(new_block + sizeof(t_block_zone) + 1);
		*clear = 0;
	}
	return (1);
}

char	malloc_zone(size_t size, t_block_zone **start_block)
{
	int				*clear;
	t_page_size		page_size;

	page_size = round_to_pagesize(size);
	ERROR_RETURN(!page_size.pages);
	if (*start_block)
	{
		while (*start_block && (*start_block)->next)
			*start_block = (*start_block)->next;
		FATAL_ERROR_RETURN(!extend_zone(*start_block, page_size));
		if (*start_block && (*start_block)->next)
			*start_block = (*start_block)->next;
	}
	else
	{
		*start_block = allocate_page(NULL, page_size.size);
		FATAL_ERROR_RETURN(!*start_block);
		(*start_block)->ps = page_size;
		(*start_block)->next = NULL;
		(*start_block)->active_members = 0;
		clear = (int *)((*start_block) + sizeof(t_block_zone) + 1);
		*clear = 0;
	}
	return (1);
}
