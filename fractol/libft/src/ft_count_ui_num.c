/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_UInum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 10:53:15 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/11 12:29:54 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_count_ui_num(unsigned int num, int base)
{
	int		count;

	count = 0;
	if ((int)num < 0)
	{
		num = num * -1;
		count++;
	}
	while (num != 0)
	{
		num = num / base;
		count++;
	}
	return (count);
}
