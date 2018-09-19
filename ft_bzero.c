/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:19:41 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/26 17:22:50 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if ((int)n < 0)
		write(1, "[ERROR] : allocation size cannot be negative\n", 45);
	else
	{
		i = 0;
		while (i < n)
		{
			((char*)s)[i] = '\0';
			i++;
		}
	}
}
