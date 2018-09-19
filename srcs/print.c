/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:37:52 by khansman          #+#    #+#             */
/*   Updated: 2017/06/14 09:37:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_total_usage(void)
{
	ft_putstr("Total : ");
	ft_putnbr((long)g_total_mem);
	ft_putstr(((long)g_total_mem > 1) ? " bytes\n" : " byte\n");
}
