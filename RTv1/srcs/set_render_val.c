/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_render_val.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 10:57:28 by daviwel           #+#    #+#             */
/*   Updated: 2016/09/02 11:49:32 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	init_render_val(t_env *env, t_render *render)
{
	render->ref_level = env->ref_level;
	render->sampling_level = env->sampling_level;
}

void	set_render_val(t_env *env, t_render *render)
{
	if (env->render == 1)
	{
		env->ref_level = render->ref_level;
		env->sampling_level = render->sampling_level;
	}
	else
	{
		env->ref_level = 0;
		env->sampling_level = 0;
	}
}
