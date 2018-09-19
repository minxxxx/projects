/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:13:49 by jlangman          #+#    #+#             */
/*   Updated: 2016/09/11 11:36:53 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	easteregg(t_env *env, char **sa)
{
	FILE	*fp;
	int		i;

	i = 0;
	(void)env;
	(void)sa;
	FILE_F;
	fp = E_FILE;
	while (i != EOF)
	{
		ft_putchar(i);
		i = getc(fp);
	}
	fclose(fp);
}
