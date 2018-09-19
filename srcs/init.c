/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:39:49 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 15:39:51 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	init_memory(void)
{
	static int	init = 0;

	if (init)
		return ;
	ft_bzero(&g_zones, sizeof(t_malloc_zones));
	g_page_size = getpagesize();
	init++;
}
