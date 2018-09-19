/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 08:06:10 by khansman          #+#    #+#             */
/*   Updated: 2017/06/13 08:06:14 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	show_tiny_list(t_block_zone *block)
{
	t_tiny_list		*tiny;

	tiny = (t_tiny_list *)((long)block + sizeof(t_block_zone) + 1);
	while (tiny->next)
	{
		if (tiny->used)
		{
			ft_putstr("0x");
			ft_print_hex_l((long)tiny + sizeof(t_tiny_list) + (long)block);
			ft_putstr(" - 0x");
			ft_print_hex_l((long)tiny + (long)tiny->next -
				sizeof(t_tiny_list) + (long)block);
			ft_putstr(" : ");
			ft_putnbr((long)tiny->next - sizeof(t_tiny_list));
			g_total_mem += (long)tiny->next - sizeof(t_tiny_list);
			ft_putstr(((long)tiny->next - sizeof(t_tiny_list) > 1) ?
				" bytes\n" : " byte\n");
		}
		tiny = (t_tiny_list *)((short)tiny->next + (long)tiny);
	}
}

void	show_small_list(t_block_zone *block)
{
	t_small_list		*small;

	small = (t_small_list *)((long)block + sizeof(t_block_zone) + 1);
	while (small->next)
	{
		if (small->used)
		{
			ft_putstr("0x");
			ft_print_hex_l((long)small + sizeof(t_small_list) + (long)block);
			ft_putstr(" - 0x");
			ft_print_hex_l((long)small + (long)small->next -
				sizeof(t_small_list) + (long)block);
			ft_putstr(" : ");
			ft_putnbr((long)small->next - sizeof(t_small_list));
			g_total_mem += (long)small->next - sizeof(t_small_list);
			ft_putstr(" bytes\n");
		}
		small = (t_small_list *)((short)small->next + (long)small);
	}
}

void	show_large_block(t_block_zone *block)
{
	ft_putstr("0x");
	ft_print_hex_l((long)block + (long)sizeof(t_block_zone));
	g_total_mem += block->active_members;
	ft_putstr(" - 0x");
	ft_print_hex_l((long)block + (long)block->active_members);
	ft_putstr(" : ");
	ft_putnbr((long)block->active_members);
	ft_putstr(" bytes\n");
}

void	show_alloc_block(t_block_zone *block, char type)
{
	if (type == TINY_BLOCK)
		ft_putstr("TINY : 0x");
	else if (type == SMALL_BLOCK)
		ft_putstr("SMALL : 0x");
	else if (type == LARGE_BLOCK)
		ft_putstr("LARGE : 0x");
	ft_print_hex_l((long)(block));
	ft_putchar('\n');
	if (type == TINY_BLOCK)
		show_tiny_list(block);
	else if (type == SMALL_BLOCK)
		show_small_list(block);
	else if (type == LARGE_BLOCK)
		show_large_block(block);
	block = block->next;
}

void	show_alloc_mem(void)
{
	t_block_zone	*block;

	block = g_zones.tiny_block;
	pthread_mutex_lock(&g_lock_all);
	g_total_mem = 0;
	while (block)
	{
		show_alloc_block(block, TINY_BLOCK);
		block = block->next;
	}
	block = g_zones.small_block;
	while (block)
	{
		show_alloc_block(block, SMALL_BLOCK);
		block = block->next;
	}
	block = g_zones.large_block;
	while (block)
	{
		show_alloc_block(block, LARGE_BLOCK);
		block = block->next;
	}
	print_total_usage();
	pthread_mutex_unlock(&g_lock_all);
}
