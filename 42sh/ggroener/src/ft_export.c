/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:22:37 by khansman          #+#    #+#             */
/*   Updated: 2016/08/22 11:28:10 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unsetenv(t_env *env, char **sa)
{
	int		k;

	k = 0;
	if (sa[0] == NULL || sa[1] == NULL)
		return ;
	while (E_EN[k] != NULL &&
			ft_strncmp(E_EN[k], sa[1], ft_strlen(sa[1])) != 0)
		k++;
	if (E_EN[k] != NULL &&
			ft_strncmp(E_EN[k], sa[1], ft_strlen(sa[1])) == 0)
	{
		free(E_EN[k]);
		while (E_EN[k + 1] != NULL)
		{
			E_EN[k] = E_EN[k + 1];
			k++;
		}
		E_EN[k] = NULL;
	}
	ERROR_6;
}

char	*ft_remove_parenthesis(char *str)
{
	int		k;

	k = 0;
	if (str == NULL)
		return (NULL);
	while (str[k] != '\"' && str[k] != '\'')
		k++;
	if (str[k] == '\"' || str[k] == '\'')
		str = &str[k];
	k = 0;
	while (str[k] != '\"' && str[k] != '\'')
		k++;
	if (str[k] == '\"' || str[k] == '\'')
		str[k] = '\0';
	return (str);
}

void	ft_setenv(t_env *env, char **sa)
{
	int		k;
	int		l;

	l = 1;
	if (ft_strchr(sa[l], '=') == NULL)
	{
		ft_putstr(E_MESS09);
		return ;
	}
	k = 0;
	while (sa[l] != NULL)
	{
		while (E_EN[k] != NULL && !(is_var(E_EN[k], sa[l])))
			k++;
		if (k > 100)
		{
			ft_putstr(E_MESS07);
			return ;
		}
		else if (ft_strchr(sa[l], '=') == NULL)
			do_command(env, sa[l]);
		else
			E_EN[k] = ft_strdup(sa[l]);
		l++;
	}
}

int		is_var(char *s1, char *s2)
{
	int		k;

	k = 0;
	while (s1[k] == s2[k] && s1[k] != '\0' && s1[k] != '=')
		k++;
	if (s1[k] == s2[k] && s1[k] == '=')
		return (1);
	return (0);
}

void	ft_export(char *sa[], int env_size, char *s)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp = sa[env_size - 1];
	temp2 = NULL;
	if (ft_strcmp(sa[env_size - 1], "#") == 0)
		sa[env_size - 1] = s;
	else
	{
		sa[env_size - 1] = ft_strjoin(sa[env_size - 1], "\n");
		temp2 = sa[env_size - 1];
		sa[env_size - 1] = ft_strjoin(sa[env_size - 1], s);
	}
	free(temp);
	if (temp2)
		free(temp2);
}
