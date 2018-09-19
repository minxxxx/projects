/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 08:31:19 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/24 14:25:49 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_shape
{
	double		dist;
	t_vector	pos;
	int			material;
}				t_shape;

typedef struct	s_sphere
{
	t_shape		shape;
	double		radius;
}				t_sphere;

typedef struct	s_plane
{
	t_shape		shape;
	t_vector	rot;
}				t_plane;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

typedef struct	s_cam
{
	double		d;
	double		h;
	double		w;
	t_vector	rot;
	t_vector	pos;
	t_vector	dir;
	t_vector	v_up;
	t_vector	n;
	t_vector	u;
	t_vector	v;
	t_vector	c;
	t_vector	l;
}				t_cam;

typedef struct	s_triangle
{
	t_shape		shape;
	t_vector	normal;
	t_vector	rot;
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
}				t_triangle;

typedef struct	s_cylinder
{
	int			inf;
	t_vector	p;
	double		scale;
	t_vector	top;
	t_vector	bot;
	t_vector	lim;
	t_vector	v;
	t_vector	rot;
	double		radius;
	t_shape		shape;
}				t_cylinder;

typedef struct	s_cone
{
	int			inf;
	int			type;
	t_vector	top;
	t_vector	bot;
	double		scale;
	t_vector	p;
	t_vector	v;
	t_vector	rot;
	double		alpha;
	t_shape		shape;
}				t_cone;

double			vector_dot(t_vector v1, t_vector v2);
t_vector		new_vector(double x, double y, double z);
t_vector		vector_sub(t_vector v1, t_vector v2);
t_vector		vector_add(t_vector v1, t_vector v2);
t_vector		vector_scale(double c, t_vector v);
t_vector		vector_cross(t_vector v1, t_vector v2);
t_vector		vector_div(t_vector *v1, t_vector *v2);
t_vector		vector_mult(t_vector v1, t_vector v2);
double			vector_dist(t_vector v1, t_vector v2);
t_vector		vector_norm(t_vector *v);
t_vector		vector_dir(t_vector s, t_vector t);
t_vector		vector_unit(t_vector v);
t_vector		vector_project(t_vector a, t_vector b);
int				vector_comp(t_vector v1, t_vector v2);

/*
** Rotation
*/

void			rotate_vec_x(double angle, t_vector *v);
void			rotate_vec_y(double angle, t_vector *v);
void			rotate_vec_z(double angle, t_vector *v);
void			rotate_tri(t_triangle *tri);
t_vector		get_cyl_normal(t_cylinder cyl, t_vector p);
t_vector		get_cone_normal(t_cone	cone, t_vector p);
t_vector		get_tri_normal(t_triangle *tri);

#endif
