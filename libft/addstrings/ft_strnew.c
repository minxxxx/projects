/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 09:38:45 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/11 09:42:32 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char) * size + 1);
	if (new)
	{
		while (i <= size)
		{
			new[i] = '\0';
			i++;
		}
	}
	return (new);
}
