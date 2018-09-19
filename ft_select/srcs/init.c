/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:17:05 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:17:07 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_init_deleg(char *str)
{
	ft_putstr_fd("ft_select: ", 2);
	if (str != NULL)
		ft_putendl_fd(str, 2);
	return (1);
}

int			ft_init(void)
{
	int		k;
	int		result;
	char	*error;
	char	*type;

	k = 0;
	type = getenv("TERM");
	if (type == NULL && (k = 1))
		ft_init_deleg("Please specify terminal (setenv TERM).");
	if (k)
		result = 0;
	else
		result = tgetent(NULL, type);
	if (result < 0 && (k = 1))
		ft_init_deleg("failed to access the termcap database.");
	if (result == 0 && (k = ft_init_deleg(NULL)))
	{
		error = ft_strdup("undefined terminal type.\n");
		ft_putstr_fd(error, 2);
		free(error);
	}
	return (k);
}
