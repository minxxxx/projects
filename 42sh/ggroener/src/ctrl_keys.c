/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 11:45:39 by jlangman          #+#    #+#             */
/*   Updated: 2016/09/06 13:12:01 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	signal_ctrl_c(int sig)
{
	(void)sig;
	ft_putstr("\b \b\b \b\n");
	ft_putstr(SH_L);
}

static void	signal_ctrl_z(int sig)
{
	(void)sig;
	ft_putstr("\b \b\b \b");
}

void		signal_gest(void)
{
	signal(SIGINT, signal_ctrl_c);
	signal(SIGTSTP, signal_ctrl_z);
}
