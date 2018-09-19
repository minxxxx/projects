/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 16:56:28 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/28 17:56:58 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_reverse(char const *s)
{
	int len;

	len = ft_strlen(s);
	len = len - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	return (len);
}

static int		ft_check_front(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		size;
	int		i;
	int		j;
	int		max;
	char	*str;

	size = ft_strlen(s);
	i = 0;
	j = 0;
	max = size;
	if (s[0] == ' ' || s[0] == '\n' || s[i] == '\t')
		i = ft_check_front(s);
	if (s[size - 1] == ' ' || s[size - 1] == '\n' || s[size - 1] == '\t')
		max = ft_check_reverse(s);
	str = (char*)malloc(sizeof(char) * (size));
	ft_bzero(str, size);
	j = 0;
	while (i <= max)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	return (str);
}
