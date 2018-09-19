/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:17:11 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/10 17:17:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**Take out this function if not needed
*/

char		*ft_create_string(t_edit *lst)
{
	int		i;
	t_edit	*tmp;
	char	*new;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	new = (char *)malloc(sizeof(char) * i + 1);
	ft_bzero(new, i + 1);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		new[i] = tmp->c;
		tmp = tmp->next;
		i++;
	}
	return (new);
}
