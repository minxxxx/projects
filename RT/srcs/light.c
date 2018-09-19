/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 08:19:55 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/09/02 11:50:12 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int	check_in_shadow(t_env *env, double t, t_vector dist,
	t_ray *light_ray)
{
	light_ray->start = OBJ.new_start;
	light_ray->dir = vector_unit(vector_scale((1 / t), dist));
	if (env->render == 1)
	{
		return (sh_spheres(env, light_ray, t)
			+ sh_tri(env, light_ray, t)
			+ sh_cylinder(env, light_ray, t)
			+ sh_cone(env, light_ray, t)
			+ sh_obj(env, light_ray, t));
	}
	else
		return (0);
}

static void	phong_shade(t_env *env, t_ray *light_ray, t_light *light)
{
	double		lam;
	double		spec;
	t_vector	dir;
	double		term;

	lam = vector_dot(light_ray->dir, OBJ.normal) * env->ref_coef;
	dir = vector_sub(light_ray->dir, env->ray.dir);
	dir = vector_scale(1.0 / sqrt(vector_dot(dir, dir)), dir);
	term = vector_dot(dir, OBJ.normal);
	term = (term > 0.0f) ? term : 0.0f;
	spec = powf(term, SPEC_POWER) * env->spec_coef;
	OBJ.col.r += lam * light->intensity.r * OBJ.cur_mat.diffuse.r;
	OBJ.col.g += lam * light->intensity.g * OBJ.cur_mat.diffuse.g;
	OBJ.col.b += lam * light->intensity.b * OBJ.cur_mat.diffuse.b;
	OBJ.col.r += spec * light->intensity.r * OBJ.cur_mat.diffuse.r;
	OBJ.col.g += spec * light->intensity.g * OBJ.cur_mat.diffuse.g;
	OBJ.col.b += spec * light->intensity.b * OBJ.cur_mat.diffuse.b;
}

static void	add_ambient(t_env *env, t_light *light)
{
	OBJ.col.r += (env->ambient_level * env->ambient_coef)
		* light->intensity.r * OBJ.cur_mat.diffuse.r;
	OBJ.col.g += (env->ambient_level * env->ambient_coef)
		* light->intensity.g * OBJ.cur_mat.diffuse.g;
	OBJ.col.b += (env->ambient_level * env->ambient_coef)
		* light->intensity.b * OBJ.cur_mat.diffuse.b;
}

void		calc_lighting(t_env *env)
{
	int			j;
	t_vector	dist;
	t_ray		light_ray;
	double		t;

	j = -1;
	env->spec_n = 0;
	while (++j < OBJ.num_lights)
	{
		add_ambient(env, &OBJ.lights[j]);
		dist = vector_sub(OBJ.lights[j].pos, OBJ.new_start);
		if (vector_dot(OBJ.normal, dist) <= 0.0F)
			continue ;
		t = sqrt(vector_dot(dist, dist));
		if (t <= EPSILON)
			continue ;
		if (check_in_shadow(env, t, dist, &light_ray) == 0)
		{
			phong_shade(env, &light_ray, &OBJ.lights[j]);
			env->spec_n++;
		}
	}
}
