/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_driver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:19:02 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:19:05 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*load_file_driver(struct stat *info)
{
	char	*result;
	int		major_nb;
	int		minor_nb;

	major_nb = major(info->st_rdev);
	minor_nb = minor(info->st_rdev);
	if (!(result = ft_strdup("")))
		error_quit("Failed to malloc major number");
	if (major_nb < 100)
		if (!(result = ft_strjoin_free1(result, " ")))
			error_quit("Failed to malloc major number");
	if (major_nb < 10)
		if (!(result = ft_strjoin_free1(result, " ")))
			error_quit("Failed to malloc major number");
	result = ft_strjoin_free3(result, ft_itoa(major_nb));
	result = ft_strjoin_free1(result, ", ");
	if (minor_nb < 100)
		if (!(result = ft_strjoin_free1(result, " ")))
			error_quit("Failed to malloc minor number");
	if (minor_nb < 10)
		if (!(result = ft_strjoin_free1(result, " ")))
			error_quit("Failed to malloc minor number");
	result = ft_strjoin_free3(result, ft_itoa(minor_nb));
	return (result);
}
