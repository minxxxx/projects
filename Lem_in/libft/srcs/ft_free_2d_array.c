/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 10:09:26 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 12:32:08 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_array(char ***str)
{
	int		i;

	if (!str)
		return ;
	i = -1;
	while (++i && *str[0][i] != '\0')
		free(str[0][i]);
	free(*str[0]);
}

void	ft_freetab(char **tab)
{
	int		i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return ;
}

void	free2d(char **arr)
{
	int		k;

	k = 0;
	if (!arr)
		return ;
	while (arr[k] != NULL)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}
