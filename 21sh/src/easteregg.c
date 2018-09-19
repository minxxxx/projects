/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easteregg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 11:13:49 by jlangman          #+#    #+#             */
/*   Updated: 2016/08/04 11:46:25 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	easteregg(t_env *env, char **sa)
{
	FILE	*fp;
	int		i;

	FILE_F;
	fp = E_FILE;
	while (i != EOF)
	{
		ft_putchar(i);
		i = getc(fp);
	}
	fclose(fp);
}
