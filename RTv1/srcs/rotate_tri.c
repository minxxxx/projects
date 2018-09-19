/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 07:46:52 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/23 12:05:03 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

void	rotate_tri(t_triangle *tri)
{
	rotate_vec_x(tri->rot.x, &tri->v1);
	rotate_vec_y(tri->rot.y, &tri->v1);
	rotate_vec_z(tri->rot.z, &tri->v1);
	rotate_vec_x(tri->rot.x, &tri->v2);
	rotate_vec_y(tri->rot.y, &tri->v2);
	rotate_vec_z(tri->rot.z, &tri->v2);
	rotate_vec_x(tri->rot.x, &tri->v3);
	rotate_vec_y(tri->rot.y, &tri->v3);
	rotate_vec_z(tri->rot.z, &tri->v3);
}
