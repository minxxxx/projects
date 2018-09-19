/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 10:37:03 by khansman          #+#    #+#             */
/*   Updated: 2016/09/06 10:37:04 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*sub_var(t_env *env, char *str)
{
	t_sub_var	var;

	var.len = ft_strlen(str);
	var.s1 = ft_strnew(var.len);
	var.s2 = ft_strnew(var.len);
	var.s3 = ft_strnew(var.len);
	var.l = ft_len_until(str, '$');
	ft_strncpy(var.s1, str, var.l);
	(str[var.l]) ? var.l++ : var.l;
	var.m = (var.l) ? ft_len_until(&str[var.l], ' ') : 0;
	(var.m) ? ft_strncpy(var.s2, &str[var.l], var.m) : (void)var.m;
	if (var.l + var.m < var.len)
		ft_strncpy(var.s3, &str[var.l + var.m], var.len - (var.m - var.l));
	var.value = find_var_val(env, var.s2);
	var.p1 = (var.value) ? ft_strjoin(var.s1, var.value) : ft_strdup(var.s1);
	var.result = ft_strjoin(var.p1, var.s3);
	free(var.s1);
	free(var.s2);
	free(var.s3);
	return (var.result);
}

int		scan_for_var(t_env *env, char **s)
{
	int			k;
	char		*str;

	k = -1;
	str = *s;
	while (str[++k])
		if (str[k] == '$')
		{
			str = sub_var(env, str);
			if (*s != NULL)
			{
				free(*s);
				*s = NULL;
			}
		}
	*s = str;
	return (k > 0);
}
