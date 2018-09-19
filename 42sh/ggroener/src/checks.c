/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:17:46 by khansman          #+#    #+#             */
/*   Updated: 2016/09/11 11:12:43 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		allowed_character(char c)
{
	if (ft_isalnum(c))
		return (1);
	if (ft_memchr(AL_SYM, c, ft_strlen(AL_SYM)) != NULL)
		return (1);
	return (0);
}

int		str_valid(t_env *env, char *str)
{
	int		k;

	k = 0;
	(void)env;
	while (str[k] != '\0')
	{
		if (!(allowed_character(str[k])))
			return (0);
		k++;
	}
	return (1);
}

int		check_line(char *line)
{
	int		check;

	check = 0;
	if (line == NULL)
		return (0);
	while (*line)
	{
		if (ft_isprint(*line) && *line != ' ' && *line != '\t')
			return (1);
		line++;
	}
	return (0);
}

void	ft_help(t_env *env, char **sa)
{
	(void)env;
	(void)sa;
	ft_putstr("\e[31mThese are the current functions\n");
	ft_putstr(" and keys you are able to use:\n\n");
	ft_putstr("\e[32mecho:     displays the input string on the std output.\n");
	ft_putstr("cd:       change the current directory to a new one.\n");
	ft_putstr("env:      view the environment.\n");
	ft_putstr("setenv:   set a new element in the environment.\n");
	ft_putstr("unsetenv: unset an element in the environment.\n");
	ft_putstr("help:     displays all available commands.\n");
	ft_putstr("F5/F6:    skip word left/right.\n");
	ft_putstr("F13/F14:  home/end keys.\n");
	ft_putstr("F17:      copies the line to the right of the cursor.\n");
	ft_putstr("F18:      copies the line.\n");
	ft_putstr("F19:      pastes the clipboard.\n");
	ft_putstr("history:  Displays a list of the previous commands used.\n");
	ft_putstr("exit:     end the program.\n");
}
