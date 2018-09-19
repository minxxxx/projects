/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:48:33 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/05 13:05:01 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			end_termios(t_env *all)
{
	write(1, "end_termios entered", 19);
	all->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(all->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, display);
	tputs(tgetstr("ve", NULL), 1, display);
	if (all->enter)
		ft_print_enter(all);
	return (1);
}

void		ft_print_enter(t_env *all)
{
	int		i;

	i = 0;
	while (all->ret[i])
	{
		ft_putstr(all->ret[i]);
		if (all->ret[i + 1])
			ft_putchar(32);
		i++;
	}
}

int			display(int c)
{
	return (write(2, &c, 1));
}
