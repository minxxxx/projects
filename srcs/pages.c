/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pages.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:42:38 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 15:42:39 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page_size	round_to_pagesize(int size)
{
	t_page_size		ps;

	ps.pages = (size / g_page_size) + 1;
	ps.size = ps.pages * g_page_size;
	if ((ps.pages * g_page_size) > MAX_INT)
		ps.pages = -1;
	return (ps);
}

void		*allocate_page(void *start_point, size_t size)
{
	void			*address;

	if (start_point == NULL)
		address = mmap(0, size, MMAP_PROT, MMAP_FLAGS, -1, 0);
	else
		address = mmap(start_point, size, MMAP_PROT, MMAP_FFLAGS, -1, 0);
	return (address);
}
