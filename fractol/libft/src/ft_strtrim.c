/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 14:31:44 by jbuys             #+#    #+#             */
/*   Updated: 2016/07/29 09:53:16 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	j--;
	while (str[j] == ' ' || str[j] == ',' || str[j] == '\t' || str[j] == '\n')
		j--;
	return (str);
}
