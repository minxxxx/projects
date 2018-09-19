/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amkhuma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:51:46 by amkhuma           #+#    #+#             */
/*   Updated: 2017/06/18 12:51:48 by amkhuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		cmp;
	int		cmp2;

	cmp = 0;
	cmp2 = 0;
	if (!s2[0])
		return ((char *)(s1));
	while (s1[cmp])
	{
		if (s1[cmp] == s2[cmp2])
			cmp2++;
		else
		{
			cmp -= cmp2;
			cmp2 = 0;
		}
		if (!s2[cmp2])
			return ((char *)(s1 + cmp - cmp2 + 1));
		cmp++;
	}
	return (NULL);
}
