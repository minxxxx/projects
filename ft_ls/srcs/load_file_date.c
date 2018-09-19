/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:18:36 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:18:39 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*get_result(char *brut_time)
{
	char	*result;

	if (!(result = ft_strsub(brut_time, 4, 7)))
		error_quit("Failed to malloc time");
	if (!(result = ft_strjoin_free1(result, " ")))
		error_quit("Failed to malloc time");
	if (brut_time[ft_strlen(brut_time) - 6] != ' ')
	{
		if (!(result = ft_strjoin_free3(result, ft_strsub(brut_time
							, ft_strlen(brut_time) - 6, 5))))
			error_quit("Failed to malloc time");
	}
	else if (!(result = ft_strjoin_free3(result
					, ft_strsub(brut_time, 20, 4))))
		error_quit("Failed to malloc time");
	return (result);
}

char			*load_file_date(t_env *env, struct stat *info)
{
	char		*brut_time;
	char		*result;
	time_t		current_time;
	time_t		ftime;
	long		delta_time;

	ftime = file_time(env, info);
	brut_time = ctime(&ftime);
	if (env->t_caps)
		return (ft_strsub(brut_time, 4, ft_strlen(brut_time) - 5));
	current_time = time(NULL);
	delta_time = current_time - ftime;
	if (delta_time > 60 * 60 * 24 * 30 * 6
			|| delta_time < -60 * 60 * 24 * 30 * 6)
		result = get_result(brut_time);
	else
		result = ft_strsub(brut_time, 4, 12);
	return (result);
}
