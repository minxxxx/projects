/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 09:42:28 by jbuys             #+#    #+#             */
/*   Updated: 2016/11/04 14:24:41 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		init_all(char **av, t_mlx *env)
{
	env->values.max_iter = 400;
	env->values.cr = -0.7;
	env->values.ci = 0.27015;
	env->values.julia_x = 1;
	env->values.julia_y = 1;
	env->values.x = 0;
	env->values.y = 0;
	env->values.av = &av[1];
	env->values.zoom = 1.0;
	env->values.move_x = 0;
	env->values.move_y = 0;
	env->values.check = 0;
}
