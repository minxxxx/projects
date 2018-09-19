/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 13:03:47 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/21 09:20:54 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

/*
** Add two vectors and return the resulting vector.
*/

t_vector	vector_add(t_vector v1, t_vector v2)
{
	return (t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
