/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:06:09 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:06:10 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LIST_H
# define FILE_LIST_H

struct s_file;

struct					s_file_list
{
	struct s_file		*file;
	struct s_file_list	*next;
};

typedef struct s_file_list	t_file_list;

#endif
