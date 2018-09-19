/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:09:12 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/15 17:55:10 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *s1, char *s2)
{
	int		count;

	count = 0;
	if (!*s1 && !*s2)
		return (1);
	else if (*s2 == '*' && !*s1)
		return (ft_match(s1, (s2 + 1)));
	else if (*s2 == '*' && *s1)
		count = ft_match((s1 + 1), s2) + ft_match(s1, (s2 + 1)) ? 1 : 0;
	else if (*s1 == *s2 && *s1)
		return (ft_match((s1 + 1), (s2 + 1)));
	return (count);
}
