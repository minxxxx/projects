/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 10:43:02 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/20 18:31:21 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int length;
	int j;

	length = 0;
	while (to_find[length] != '\0')
			length++;
	if (length == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j])
		{
			if (j == length - 1)
				return (str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int main (void)
{
	char *str = "This sentence.";
	char *to_find = "ten";

   char *result = ft_strstr(str, to_find);
   printf("%s\n", str);
   printf("%p\n", str);
   return (0);
}
