/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_list.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:04:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:04:25 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTORY_LIST_H
# define DIRECTORY_LIST_H

typedef struct					s_directory_list
{
	char						*path;
	char						*name;
	struct s_directory_list		*next;
}								t_directory_list;

#endif
