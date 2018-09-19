/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 09:52:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/22 14:07:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		vector_comp(t_vector v1, t_vector v2)
{
	if (fabs(v1.x - v2.x) > EPSILON)
		return (0);
	if (fabs(v1.y - v2.y) > EPSILON)
		return (0);
	if (fabs(v1.z - v2.z) > EPSILON)
		return (0);
	return (1);
}
