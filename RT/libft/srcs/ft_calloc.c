/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 08:19:39 by oexall            #+#    #+#             */
/*   Updated: 2016/08/22 08:21:14 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count <= 0 || !(tmp = malloc(size * count)))
		return (NULL);
	ft_memset(tmp, 0, count);
	return (tmp);
}
