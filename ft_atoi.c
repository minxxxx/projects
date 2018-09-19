/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:53:39 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/30 18:28:05 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *str)
{
	int i;
	int sum;

	i = 0;	
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||\
				str[i] == '\v' || str[i] == '\f' || str[i] == '\r' ||\
				str[i] == '0')
			i++;
		else
			break ;
	}
	if (str[i] == '-' && (ft_isdigit(str[i + 1] == '0')))
	{
		i++;
		while (str[i] == '0')
			i++;
		return (-ft_atoi(&str[i]));
	}
	else if (str[i] == '-' && !ft_isdigit(str[i + 1])) 
		return (0);
	sum = 0;
	while (str[i] != '\0')
	{	
		if ((str[i] >= '0') && (str[i] <= '9'))
			sum = (sum * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (sum);
}

int		main(void)
{
	int i;

	char n[] = "-1235 IS WHERE MY CAT IS";
	i = ft_atoi(n);
	printf("%d\n", i);
	return (0);
}

