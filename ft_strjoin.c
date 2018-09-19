/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:36:33 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/27 09:04:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*str;

	size = (ft_strlen(s1) + ft_strlen(s2));
	str = (char*)malloc(sizeof(char) * (size));
	ft_bzero(str, size);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	str[size] = '\0';
	return (str);
}
