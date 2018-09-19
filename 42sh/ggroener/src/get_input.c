/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 09:34:53 by khansman          #+#    #+#             */
/*   Updated: 2016/09/11 11:30:57 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_key(t_env *env)
{
	char		key[10];
	int			k;

	k = 0;
	key[k] = I_TMP;
	if (I_TMP == '\e')
	{
		read(1, &key[++k], 1);
		read(1, &key[++k], 1);
		if ('1' <= key[k] && key[k] <= '3')
		{
			read(1, &key[++k], 1);
			if (key[k] != '~')
				read(1, &key[++k], 1);
		}
	}
	key[++k] = '\0';
	key_handler(env, key);
	return ;
}

void	print_quote(t_env *env)
{
	char	*line;
	char	*temp;

	if (I_L1 != NULL && I_L2 != NULL)
		line = ft_strjoin(I_L1, I_L2);
	else
		line = (I_L1 != NULL) ? ft_strdup(I_L1) : ft_strdup(I_L2);
	temp = ft_strrchr(line, '\n');
	if (temp == NULL)
		return ;
	while (*++temp)
		ft_putchar(*temp);
	free(line);
}

void	print_line(t_env *env)
{
	int			k;
	int			l;

	if (I_L1 == NULL && I_L2 == NULL)
		return ;
	k = ft_termsize(0);
	CL_LINE;
	l = ((int)ft_strlen(I_L1) >= (int)ft_termsize(0) - 5) ?
		ft_strlen(I_L1) + 5 - (ft_termsize(0) - 1) : -1;
	(I_TMP2 == 0) ? ft_putstr(SH_L) : ft_putstr(SH_Q);
	if (I_TMP2 == 0)
	{
		while (I_L1 && I_L1[++l])
			if (I_L1[l] != '\n' && I_L1[l] != '\v' && I_L1[l] != '\r')
				ft_putchar(I_L1[l]);
		k -= l + 5;
		l = -1;
		while (I_L2 && I_L2[++l] && l < k)
			if (I_L2[l] != '\n' && I_L2[l] != '\v' && I_L2[l] != '\r')
				ft_putchar(I_L2[l]);
		while (l-- > 0)
			ft_putchar('\b');
	}
	else
		print_quote(env);
}

int		get_input(t_env *env, int fd, char **line)
{
	I_TMP = 23;
	I_L1 = NULL;
	I_C1 = -1;
	while ((I_TMP != '\r' && I_TMP != '\n' && I_TMP != '\0')
		|| !check_par(env))
	{
		print_line(env);
		read(fd, &I_TMP, 1);
		if (I_C1 + 2 % LINE_LEN == 0 || I_C1 == -1)
			I_L1 = re_malloc(I_L1, I_C1 + 1);
		if (!ft_isprint(I_TMP) && I_TMP != '\0' && I_TMP != '\r'
				&& I_TMP != '\n')
			get_key(env);
		else
			I_L1[++I_C1] = I_TMP;
	}
	if (I_C1 + 1)
		I_L1[I_C1] = 0;
	*line = ft_strjoin(I_L1, I_L2);
	if (++I_C1)
		return (1);
	return (0);
}
