/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:51:28 by amkhuma           #+#    #+#             */
/*   Updated: 2017/06/18 12:51:31 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*fct;

	fct = NULL;
	while (*s)
	{
		if (*s == (char)c)
			fct = (char *)s;
		s++;
	}
	if (*s == (char)c)
		fct = (char *)s;
	return (fct);
}
