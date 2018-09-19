/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_project.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 08:56:35 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/08/21 09:36:19 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

/*
** Project vector a onto vector b, producing a new vector returned by function.
*/

t_vector	vector_project(t_vector a, t_vector b)
{
	return (vector_scale(vector_dot(a, b) / vector_dot(b, b), b));
}
