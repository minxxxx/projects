/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 17:07:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/15 17:41:52 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char **s, unsigned int start, size_t len, int pfree)
{
	char	*ret;

	ret = ft_strsub((const char *)*s, start, len);
	if (pfree)
	{
		free(*s);
		*s = NULL;
	}
	return (ret);
}
