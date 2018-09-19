/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_n_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 08:57:41 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:43:37 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	set_comment(t_info *info, int i)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (INPUT[i][++j] != '"')
	{
		if (INPUT[i][j] == '\0')
		{
			ft_putstr_fd("Error : incorrect format with comment\n", 2);
			exit(0);
		}
	}
	while (INPUT[i][++j] != '"')
	{
		if (INPUT[i][j] == '\0' || j > COMMENT_LENGTH)
		{
			ft_putstr_fd("Error : incorrect format with comment\n", 2);
			exit(0);
		}
		info->comment[k] = INPUT[i][j];
		k++;
	}
	info->comment[k] = '\0';
}

void	set_name(t_info *info, int i)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (INPUT[i][++j] != '"')
	{
		if (INPUT[i][j] == '\0')
		{
			ft_putstr_fd("Error : incorrect format with name\n", 2);
			exit(0);
		}
	}
	while (INPUT[i][++j] != '"')
	{
		if (INPUT[i][j] == '\0' || j > PROG_NAME_LENGTH)
		{
			ft_putstr_fd("Error : incorrect format with name\n", 2);
			exit(0);
		}
		info->name[k] = INPUT[i][j];
		k++;
	}
	info->name[k] = '\0';
}

/*
** This function finds and stores the warrior's name or comment
*/

void	get_n_or_c(t_info *info, int i, int *name, int *comm)
{
	if (ft_strncmp(INPUT[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		*name = 1;
		set_name(info, i);
	}
	else if (ft_strncmp(INPUT[i], COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		*comm = 1;
		set_comment(info, i);
	}
	else
	{
		ft_putstr_fd("Error : incorrect name or command string\n", 2);
		exit(0);
	}
}

/*
** This function looks for a name and comment and displays an error if they are
** not found
*/

void	check_nc(t_info *info)
{
	int	i;
	int	name_found;
	int	comm_found;

	i = 0;
	name_found = 0;
	comm_found = 0;
	while (INPUT[i])
	{
		if (INPUT[i][0] == '.')
		{
			get_n_or_c(info, i, &name_found, &comm_found);
		}
		else if (INPUT[i][0] != '#' && INPUT[i][0] != '\0' && (name_found == 0
					|| comm_found == 0))
		{
			ft_putstr_fd("Error : Name and comment must appear first\n", 2);
			exit(0);
		}
		i++;
	}
}
