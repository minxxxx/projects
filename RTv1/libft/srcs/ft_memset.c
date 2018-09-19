/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 08:28:09 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 10:33:39 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char*)str;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
