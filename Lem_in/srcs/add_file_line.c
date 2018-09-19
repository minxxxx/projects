/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:55:45 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/24 13:21:09 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_file_line(t_env *env, char *line)
{
	char	**new;
	int		len;
	int		i;

	len = 0;
	while (env->file[len])
		len++;
	if (!(new = malloc(sizeof(*new) * (len + 2))))
		error_quit("Failed to malloc new tab");
	i = 0;
	while (env->file[i])
	{
		new[i] = env->file[i];
		i++;
	}
	new[i++] = line;
	new[i++] = NULL;
	free(env->file);
	env->file = new;
}
