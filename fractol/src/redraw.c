/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 09:32:56 by jbuys             #+#    #+#             */
/*   Updated: 2016/10/04 14:10:23 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		loop_main(t_mlx *env)
{
	env->values.y = 0;
	if (ft_strcmp(*env->values.av, "Mandelbrot") == 0)
		mandelbrot_calc(env);
	if (ft_strcmp(*env->values.av, "Julia") == 0)
		julia_calc(env);
	if (ft_strcmp(*env->values.av, "Burningship") == 0)
		burningship_calc(env);
}

void			redraw(t_mlx *env)
{
	env->img = mlx_new_image(env->win, WIN_W, WIN_H);
	env->data = mlx_get_data_addr(env->img, &env->bpp,
		&env->size_line, &env->endian);
	loop_main(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
