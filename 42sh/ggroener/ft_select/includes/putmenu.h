/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmenu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 12:16:11 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 12:16:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTMENU_H
# define PUTMENU_H

typedef struct	s_putmenu
{
	int			*d;
	int			argc;
	int			*pos;
	t_choice	**choice;
}				t_putmenu;

#endif
