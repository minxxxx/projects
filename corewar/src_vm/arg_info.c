/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:37:45 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/18 09:03:50 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

int			valid_type(int type)
{
	if (type != REG_CODE && type != DIR_CODE && type != IND_CODE)
		return (0);
	else
		return (1);
}

/*
** Uses encoding byte to generate a int* containing the arg types,
** index corresponds to index of arg
*/

int			*get_arg_types(char *e_byte)
{
	int	*arg_types;
	int	i;
	int	temp;

	arg_types = (int*)malloc(sizeof(int) * 4);
	i = 0;
	while (i < 4)
	{
		temp = *(int*)e_byte;
		arg_types[i] = (temp >> (6 - (i * 2))) & 3;
		i++;
	}
	return (arg_types);
}

/*
** Returns the size (octets) of an argument based on type.
*/

int			arg_size(int arg_type)
{
	if (arg_type == REG_CODE)
		return (1);
	if (arg_type == DIR_CODE)
		return (DIR_SIZE);
	if (arg_type == IND_CODE)
		return (IND_SIZE);
	return (0);
}

int			total_arg_n(int *arg_sizes)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 4)
	{
		total += arg_sizes[i];
		i++;
	}
	return (total);
}

int			*get_arg_sizes(t_op_run *new, t_env *env)
{
	int	i;

	i = 0;
	new->arg_sizes = (int*)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		if (i < OP(new->op).nbr_args)
		{
			if (new->arg_types[i] == T_DIR && OP(new->op).dir_as_index == TRUE)
				new->arg_sizes[i] = IND_SIZE;
			else
				new->arg_sizes[i] = arg_size(new->arg_types[i]);
		}
		else
			new->arg_sizes[i] = 0;
		i++;
	}
	return (new->arg_sizes);
}
