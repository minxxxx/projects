/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 09:16:50 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:22:15 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

void	free_commands(t_command *com)
{
	t_command	*temp;
	int			i;

	i = -1;
	temp = com;
	while (temp->params && temp->params[++i])
		free(temp->params[i]);
	if (temp->params)
		free(temp->params);
	free(temp);
}
