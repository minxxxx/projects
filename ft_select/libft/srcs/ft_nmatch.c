/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:09:27 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/15 17:55:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if (*s2 == '*' && !*s1)
		return (ft_nmatch(s1, (s2 + 1)));
	else if (*s2 == '*' && *s1)
		return (ft_nmatch((s1 + 1), s2) + ft_nmatch(s1, (s2 + 1)));
	else if (*s1 == *s2 && *s1)
		return (ft_nmatch((s1 + 1), (s2 + 1)));
	return (0);
}
