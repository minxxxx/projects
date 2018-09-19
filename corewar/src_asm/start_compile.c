/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_compile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 07:53:25 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:37:52 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** This function loops through the file to see if there are no syntax errors
** while also storing all commands and labels
*/

int		print_error(int i)
{
	ft_putstr_fd("Syntax error line : ", 2);
	ft_putnbr_fd(i + 1, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

void	start_compile(t_info *info)
{
	int	i;
	int	will_exit;

	i = -1;
	will_exit = 0;
	a_fill_op_tab(info);
	info->num_labels = 0;
	info->labels = NULL;
	info->header.prog_size = 0;
	while (INPUT[++i])
		if (read_line(info, INPUT[i], i) == -1)
			will_exit = print_error(i);
	if (will_exit == 1)
		exit(-1);
	i = -1;
	while (INPUT[++i])
		if (interpret_line(INPUT[i], info, i) == -1)
			will_exit = print_error(i);
	if (will_exit == 1)
		exit(-1);
}
