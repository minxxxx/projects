/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 09:38:13 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/01 13:03:07 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

/*
** Prints out error message if input arguments are incorrectly formatted.
*/

void	arg_err(int err, char *arg)
{
	if (err == ER_ARGF)
		ft_putstr_fd("Argument format error, usage :\n\
			./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n", 2);
	else if (err == ER_FILE)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(" is not a corewar executable.\n", 2);
	}
	else if (err == ER_NOTNUM)
		ft_putstr_fd("-n [number] must be an integer..\n", 2);
	else if (err == ER_DUPNUM)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": program number already in use.\n", 2);
	}
	else if (err == ER_MALLOC)
	{
		ft_putstr_fd("Error allocating memory with malloc at", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(".\n", 2);
	}
	exit(-1);
}

/*
** check_args runs validity checks on arguments.
**  - formatting
**  - invalid files - only checks extension (.cor) & if file exists.
**  - duplicate numbers
*/

void	check_flag(char **argv, int i, int argc)
{
	if (ft_strlen(argv[i]) > 1)
	{
		if (ft_strcmp(argv[i], "-dump") != 0
			&& ft_strcmp(argv[i], "-n") != 0 && i == 1)
			arg_err(ER_ARGF, argv[i]);
		else if (i != 1 && ft_strcmp("-n", argv[i]) != 0)
			arg_err(ER_ARGF, argv[i]);
		if (i + 1 + (ft_strcmp(argv[i], "-n") == 0) >= argc)
			arg_err(ER_ARGF, argv[i]);
		else
		{
			if (is_numeric(argv[i + 1]) == 0 || check_int(argv[i + 1]) == 0)
				arg_err(ER_ARGF, argv[i]);
		}
	}
	else
		arg_err(ER_ARGF, argv[i]);
}

void	check_file(char *arg)
{
	int	fd;
	int	i;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		arg_err(ER_FILE, arg);
	close(fd);
	i = ft_strlen(arg);
	if (i < 5)
		arg_err(ER_FILE, arg);
	i -= 4;
	if (i > 0)
		if (ft_strcmp(".cor", &arg[i]) != 0)
			arg_err(ER_FILE, arg);
}

void	check_args(int argc, char **argv, t_env *env)
{
	int	i;
	int	players;

	i = 1;
	players = 0;
	if (argc == 1)
		arg_err(ER_ARGF, argv[i]);
	while (i < argc)
	{
		if (argv[i][0] == '-')
			check_flag(argv, i, argc);
		else if (ft_strcmp("-n", argv[i - 1]) != 0
				&& ft_strcmp("-dump", argv[i - 1]) != 0)
		{
			check_file(argv[i]);
			env->p_count++;
		}
		i++;
	}
	check_player_numbers(argc, argv);
	if (env->p_count == 0)
		arg_err(ER_ARGF, argv[i]);
}
