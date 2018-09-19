/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 07:46:46 by jbuys             #+#    #+#             */
/*   Updated: 2016/06/04 16:12:37 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *restrict str, ...)
{
	va_list		ap;
	size_t		i;

	va_start(ap, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && do_compare(&str[i + 1]) == 1)
		{
			printf_format(ap, &str[i + 1]);
			i++;
		}
		else if (str[i] == '%' && do_compare(&str[i + 1]) == 2)
			i = i + do_flags(ap, &str[i + 1]);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (0);
}
