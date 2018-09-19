/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:03:58 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:04:04 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_H
# define DIRECTORY_H

# include "file_list.h"

struct s_directory_list;

typedef struct				s_directory
{
	char					*path;
	int						links_len;
	int						user_len;
	int						group_len;
	int						size_len;
	int						date_len;
	int						total_links;
	t_file_list				*files;
}							t_directory;

#endif
