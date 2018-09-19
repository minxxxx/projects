/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 12:10:07 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/04 12:13:24 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rt.h"

typedef struct	s_light
{
	t_vector	pos;
	t_col		intensity;
}				t_light;

#endif
