/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:05:27 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/21 09:33:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function takes start vector (s) and a point (t) as a direction vector and
** returns normalized direction vector.
*/

#include <rt.h>

t_vector	vector_dir(t_vector s, t_vector t)
{
	t_vector	ret;

	ret = vector_sub(t, s);
	return (vector_norm(&ret));
}
