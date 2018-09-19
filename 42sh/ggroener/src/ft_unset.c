/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:23:34 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:23:47 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_removestr(char *big, char *little)
{
	char	*start;
	int		k;
	int		l;
	char	*str;

	k = -1;
	str = (char *)malloc(ft_strlen(big) + 1);
	start = ft_strstr(big, little);
	while (big[++k] != *start)
		str[k] = big[k];
	l = k;
	while (big[l] == *start || big[l] == '\n')
	{
		start++;
		l++;
	}
	while (big[l] != '\0')
	{
		str[k] = big[l];
		k++;
		l++;
	}
	big = str;
}

void	ft_unset(char ***sa, char *var)
{
	int		k;
	char	*temp;

	k = 0;
	temp = NULL;
	if (var == NULL)
		return ;
	while (*sa[k] != NULL)
	{
		if (ft_strstr(*sa[k], var) != NULL)
			ft_removestr(*sa[k], var);
		k++;
	}
}
