/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupl_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:58:30 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/01 14:14:37 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

static int		is_n(char *arg)
{
	if (ft_strlen(arg) == 2)
	{
		if (ft_strcmp(arg, "-n") == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static int		check_dup(int *p_buf, int *p, char *arg)
{
	int	i;
	int	temp;

	temp = ft_atoi(arg);
	i = 0;
	while (i < *p)
	{
		if (p_buf[i] == temp)
			arg_err(ER_DUPNUM, arg);
		i++;
	}
	p_buf[*p] = temp;
	*p = *p + 1;
	return (temp);
}

static int		get_def(int *p_buf, int p)
{
	int			dup;
	static int	def = 1;
	int			i;

	dup = 1;
	while (dup)
	{
		dup = 0;
		i = 0;
		while (i < p)
		{
			if (def == p_buf[i])
				dup = 1;
			i++;
		}
		def += dup;
	}
	return (def);
}

void			check_player_numbers(int argc, char **argv)
{
	int i;
	int	p;
	int	*p_buf;

	i = 0;
	p = 0;
	if ((p_buf = (int*)malloc(sizeof(int) * argc)) == NULL)
		arg_err(ER_MALLOC, "check_player_numbers\n");
	while (++i < argc)
	{
		if (is_n(argv[i]))
		{
			if (i + 1 < argc)
				if (!(is_numeric(argv[i + 1]) && check_int(argv[i + 1])))
					arg_err(ER_NOTNUM, argv[i + 1]);
			p_buf[p] = check_dup(p_buf, &p, argv[i + 1]);
			i += 2;
		}
		else if (!(ARG_DUMP(i) || (i == 2 && ARG_DUMP(i - 1))))
		{
			p_buf[p] = get_def(p_buf, p);
			p++;
		}
	}
	free(p_buf);
}
