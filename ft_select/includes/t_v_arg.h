/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_v_arg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 16:20:22 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/11 16:22:34 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_V_ARG_H
# define T_V_ARG_H

typedef struct		s_v_arg
{
	int				i;
	char			c;
	char			*s;
	int				type;
	struct s_v_arg	*next;
}					t_v_arg;

#endif
