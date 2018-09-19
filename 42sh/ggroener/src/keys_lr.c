/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_lr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 08:58:50 by khansman          #+#    #+#             */
/*   Updated: 2016/09/09 13:28:06 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	Adds a char to the beginning of a string
*/

char	*ft_add_char_start(char *str, char c)
{
	char	*s;
	int		k;

	s = (char *)ft_strnew(ft_strlen(str) + 3);
	k = -1;
	*s = c;
	while (str && *str && str[++k])
		s[k + 1] = str[k];
	return (s);
}

/*
**	Adds a char to the end of a string
*/

char	*ft_add_char_end(char *str, char c)
{
	int		k;
	char	*s;

	s = (char *)ft_strnew(ft_strlen(str) + 3);
	k = -1;
	while (str && *str && str[++k])
		s[k] = str[k];
	k = (k == -1) ? 0 : k;
	s[k] = c;
	return (s);
}

/*
**	Copies everything but the first char from a string.
*/

char	*ft_str_inc_dup(char *str)
{
	char	*s;
	int		k;

	if (ft_strlen(str) < 2)
		return (NULL);
	s = (char *)ft_strnew(ft_strlen(str) + 2);
	k = 0;
	while (str[++k])
		s[k - 1] = str[k];
	return (s);
}

void	ke_left(t_env *env)
{
	int		k;
	char	*temp;

	temp = I_L2;
	k = ft_strlen(I_L1) - 1;
	if (I_L1 == NULL || ft_strlen(I_L1) == 0)
		return ;
	I_L2 = ft_add_char_start(temp, I_L1[k]);
	if (temp != NULL)
		free(temp);
	I_L1[k] = '\0';
	I_C1 = k - 1;
	I_C2 = ft_strlen(I_L2) - 1;
}

void	ke_right(t_env *env)
{
	char	*k;
	char	*temp;

	temp = I_L1;
	if (I_L2 == NULL || ft_strlen(I_L2) == 0)
		return ;
	k = ft_str_inc_dup((I_L2));
	I_L1 = ft_add_char_end(temp, *I_L2);
	if (temp != NULL)
		free(temp);
	I_C1 = ft_strlen(I_L1) - 1;
	I_C2 = ft_strlen(I_L2) - 1;
	if (I_L2 != NULL)
		free(I_L2);
	I_L2 = k;
}
