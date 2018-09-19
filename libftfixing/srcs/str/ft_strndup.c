/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 20:47:44 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/04 20:47:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int len)
{
	char	*rep;

	if ((rep = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	ft_strncpy(rep, str, len);
	rep[len] = '\0';
	return (rep);
}
