/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 13:20:34 by lmucassi          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:06 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;

	dst = (char *)malloc(sizeof(*dst) * ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	else
	{
		ft_strcpy(dst, s);
	}
	return (dst);
}
