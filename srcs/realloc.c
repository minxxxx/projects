/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:48:21 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 08:48:22 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

/*
**   The realloc() function tries to change the size of the allocation pointed
**   to by ptr to size, and returns ptr.  If there is not enough room to
**   enlarge the memory allocation pointed to by ptr, realloc() creates a new
**   allocation, copies as much of the old data pointed to by ptr as will fit
**   to the new allocation, frees the old allocation, and returns a pointer to
**   the allocated memory.  If ptr is NULL, realloc() is identical to a call
**   to malloc() for size bytes.  If size is zero and ptr is not NULL, a new,
**   minimum sized object is allocated and the original object is freed.
**   When extending a region allocated with calloc(3), realloc(3) does not
**   guarantee that the additional memory is also zero-filled.
*/

/*
**  I am sorry Kalilo but this is reallocf
**  At least we got one bonus
**  The reallocf() function is identical to the realloc() function, except
**  that it will free the passed pointer when the requested memory cannot be
**  allocated.  This is a FreeBSD specific API designed to ease the problems
**  with traditional coding styles for realloc causing memory leaks in
**  libraries.
*/

static void	copy_alloced_data(t_block_data data, void *new_mem,
	void *ptr, size_t size)
{
	t_tiny_list		*tiny;
	t_small_list	*small;

	if (data.block_type == TINY_BLOCK)
	{
		tiny = (t_tiny_list *)((long)ptr - sizeof(t_tiny_list));
		ft_memmove(new_mem, ptr,
			(size < (size_t)tiny->next) ? size : tiny->next);
	}
	else if (data.block_type == SMALL_BLOCK)
	{
		small = (t_small_list *)((long)ptr - sizeof(t_small_list));
		ft_memmove(new_mem, ptr,
			(size < (size_t)small->next) ? size : small->next);
	}
	else if (data.block_type == LARGE_BLOCK)
		ft_memmove(new_mem, ptr,
			(data.block->ps.size - sizeof(t_block_data) - 1));
}

void		*realloc(void *ptr, size_t size)
{
	t_block_data	block_data;
	void			*new_ptr;

	init_memory();
	block_data = find_block(ptr);
	if (block_data.block_type == TINY_BLOCK && size <= TINY_MAX &&
			realloc_tiny_block(ptr, size))
		return (ptr);
	if (block_data.block_type == SMALL_BLOCK && size <= SMALL_MAX &&
			realloc_small_block(ptr, size))
		return (ptr);
	if (block_data.block_type == LARGE_BLOCK)
		return (realloc_large_block(ptr, size));
	new_ptr = malloc(size);
	copy_alloced_data(block_data, new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
