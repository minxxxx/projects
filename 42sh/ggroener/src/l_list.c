/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 10:20:16 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/11 10:20:18 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		l_list(t_edit **lst_e)
{
	int		lengh;
	t_edit	*tmp;

	lengh = 0;
	tmp = *lst_e;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		lengh++;
	}
	return (lengh);
}
