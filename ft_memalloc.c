/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:56:08 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/26 18:03:26 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	*ft_memalloc(size_t size)
{
	void *str;

	if ((int)size < 0)
	{
		write(1, "Can't assign a negative number for allocation\n", 46);
		return (NULL);
	}
	else
	{
		str = malloc(size);
		if (str)
			ft_bzero(str, size);
		return (str);
	}
}
