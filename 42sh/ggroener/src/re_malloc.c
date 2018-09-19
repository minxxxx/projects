/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:06:38 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/09/11 15:07:00 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**re_2d_malloc(char **arr, size_t size)
{
	char	**temp;
	int		cnt;

	cnt = 0;
	temp = (char **)malloc(sizeof(char *) * (size + 5));
	while (temp[cnt])
	{
		temp[cnt] = NULL;
		cnt++;
	}
	cnt = 0;
	if (size > 0)
	{
		while (arr[cnt] && arr[cnt] != NULL)
		{
			temp[cnt] = ft_strdup(arr[cnt]);
			cnt++;
		}
	}
	return (temp);
}

char	***re_3d_malloc(char ***arr, size_t size)
{
	char	***temp;
	int		cnt;

	cnt = 0;
	temp = (char ***)malloc(sizeof(char **) * (size + 10));
	while (temp[cnt])
	{
		temp[cnt] = NULL;
		cnt++;
	}
	cnt = 0;
	if (size > 0)
	{
		while (arr[cnt] && arr[cnt] != NULL)
		{
			temp[cnt] = arr[cnt];
			cnt++;
		}
	}
	return (temp);
}
