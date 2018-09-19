/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 09:25:01 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 09:25:03 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/mman.h>

# include "../libft/includes/libft.h"

# define TINY_MAX 127
# define SMALL_MAX 32768

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define FATAL_ERROR_RETURN(x) if(x)return(-1)
# define ERROR_RETURN(x) if(x)return(0)
# define SUCCESS_RETURN(X) if(x)return(1)

typedef struct			s_tiny_list
{
	unsigned char		used : 1;
	unsigned char		next : 7;
}						t_tiny_list;

typedef struct			s_small_list
{
	unsigned short		used : 1;
	unsigned short		next : 15;
}						t_small_list;

typedef struct			s_page_size
{
	int							pages;
	int							size;
}						t_page_size;

typedef struct			s_block_zone
{
	struct s_block_zone	*next;
	t_page_size			ps;
}						t_block_zone;

typedef struct			s_malloc_zones
{
	t_block_zone		*tiny_block;
	t_block_zone		*small_block;
	t_block_zone		*large_block;
}						t_malloc_zones;

t_malloc_zones			g_zones;
int						g_page_size;

void	init_memory(void)
{
	ft_bzero(&g_zones, sizeof(t_malloc_zones));
	g_page_size = getpagesize();
}

t_page_size	round_to_pagesize(int size)
{
	t_page_size		ps;

	ps.pages = (size / g_page_size) + 1;
	ps.size = ps.pages * g_page_size;
	if ((ps.pages * g_page_size) > MAX_INT)
		ps.pages = -1;
	return (ps);
}

void	*allocate_page(void	*start_point, size_t size)
{
	void	*address;

	if (start_point == NULL)
		address = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	else
		address = mmap(start_point, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE |  MAP_FIXED, -1, 0);
	
	return (address);
}

char	extend_zone(t_block_zone *block, t_page_size page_size)
{
	t_block_zone	*new_block;

	if ((new_block = allocate_page(block->ps.size + block, page_size.size)) != NULL)
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
	}
	return (1);
}

char	malloc_zone(size_t size, t_block_zone **start_block)
{
	t_block_zone	*block;
	t_page_size		page_size;

	page_size = round_to_pagesize(size);
	ERROR_RETURN(!page_size.pages);
	block = *start_block;
	if (block)
	{
		while (block && block->next)
			block = block->next;
		FATAL_ERROR_RETURN(!extend_zone(block, page_size));
		block = block->next;
	}
	else
	{
		*start_block = allocate_page(NULL, page_size.size);
		FATAL_ERROR_RETURN(!*start_block);
		block->ps = page_size;
		block->next = NULL;
	}
	return (1);
}

// char	malloc_small_zone(size_t size)
// {
// 	if (g_zones.small_block == NULL)
// 		g_zones.small_block = allocate_page(NULL, 2 * g_page_size);
// 	if (g_zones.small_block == NULL)
// 		return (0);
// 	return (1);
// }
