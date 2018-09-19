/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:45:23 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/22 13:35:06 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

typedef struct	s_reader
{
	char		*line;
	int			link_part;
	int			is_start;
	int			is_end;
}				t_reader;

#endif
