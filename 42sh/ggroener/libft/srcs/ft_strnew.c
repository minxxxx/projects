/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:26:25 by ggroener          #+#    #+#             */
/*   Updated: 2016/08/07 11:12:13 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	if (size <= 0)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
