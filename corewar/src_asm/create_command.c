/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 07:35:03 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/31 07:19:37 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Creates a new command using the current line
*/

t_command	*set_nc(char *params, int *index, t_info *info)
{
	t_command	*nc;
	char		*trim;

	nc = (t_command *)malloc(sizeof(t_command));
	nc->opcode = info->op_tab[*index].code;
	nc->encoding_byte = '\0';
	nc->op_tab_index = *index;
	trim = str_trim(params);
	nc->params = ft_strsplit(trim, SEPERATOR_CHAR);
	nc->num_params = count_arr(nc->params);
	nc->dir_as_index = info->op_tab[*index].dir_as_index;
	free(trim);
	return (nc);
}

t_list		*create_command(char *params, int *index, t_info *info)
{
	t_list		*link;
	t_command	*nc;

	nc = set_nc(params, index, info);
	if ((nc->has_encoding = info->op_tab[nc->op_tab_index].n_byte) == TRUE)
	{
		if ((nc->encoding_byte = get_encoding_byte(nc->params, nc->num_params,
						nc->op_tab_index, info)) == '\0')
			*index = -1;
	}
	if (get_param_bytes(nc->params, nc->num_params, nc, info) == -1)
	{
		*index = -1;
		return (NULL);
	}
	if (nc->has_encoding == TRUE)
		nc->command_bytes += 2;
	else
		nc->command_bytes += 1;
	nc->line_nbr = info->line_nbr;
	info->header.prog_size += nc->command_bytes;
	link = ft_lstnew((void *)nc);
	return (link);
}
