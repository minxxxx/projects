/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 16:02:53 by khansman          #+#    #+#             */
/*   Updated: 2017/06/13 16:02:55 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	ft_print_hex_l(unsigned long num)
{
	static char *base = "0123456789ABCDEF";

	if (num >= 16)
		ft_print_hex_l(num / 16);
	write(1, (base + (num % 16)), 1);
}
