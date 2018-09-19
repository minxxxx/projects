/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 12:04:49 by amkhuma           #+#    #+#             */
/*   Updated: 2017/09/10 12:04:52 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstrnew(size_t size)
{
	char	**s;
	size_t	i;

	i = 0;
	if (!(s = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < (size))
		s[i++] = NULL;
	s[i] = NULL;
	return (s);
}
