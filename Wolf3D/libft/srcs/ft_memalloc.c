/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:49:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/01/03 09:24:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ret;
	size_t	i;

	ret = malloc(size);
	if (!ret)
		return (ret);
	i = 0;
	while (i < size)
	{
		((unsigned char*)ret)[i] = 0;
		i++;
	}
	return (ret);
}
