/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:26:22 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:34:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		env_valid(char *s)
{
	int		k;
	int		l;

	k = 0;
	l = ft_strlen(s);
	while (k < l)
	{
		if (!(allowed_character(s[k])))
			return (0);
		k++;
	}
	return (1);
}

void	set_env(t_env *env, char *s)
{
	char	*temp;
	int		check;

	temp = NULL;
	check = 0;
	if (check == env_valid(s))
	{
		temp = env->a;
		env->a = ft_strjoin(env->a, s);
		free(temp);
	}
	else
		error(0);
	if (check == 2)
		command(env, ft_strchr(s, ' '));
}
