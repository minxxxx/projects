/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 08:59:59 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/13 11:58:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_string;
	size_t	i;

	i = 0;
	new_string = (char*)ft_memalloc(size + 1);
	while (i <= size && new_string != NULL)
	{
		new_string[i] = '\0';
		i++;
	}
	return (new_string);
}
