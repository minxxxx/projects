/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 18:07:11 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/11 18:07:14 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

typedef struct			s_source
{
	char				*path;
	char				*display_path;
	int					sort_date;
	struct s_source		*next;
}						t_source;

#endif
