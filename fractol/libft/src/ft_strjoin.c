/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 13:16:41 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/09 15:38:56 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*temp;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	temp = (char *)malloc(sizeof(char) * len);
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}
