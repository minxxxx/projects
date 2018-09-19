/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 08:52:14 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/07/07 09:43:43 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static char	*set_temp(char *ptr, char c)
{
	char	*temp;

	temp = ft_strchr(ptr, c);
	if (temp == NULL)
	{
		ft_putstr_fd("File input error - error reading light.\n", 2);
		exit(-1);
	}
	return (temp);
}

static void	set_pos(t_vector *pos, char *temp)
{
	temp = set_temp(temp, 'x');
	pos->x = 1.0f * ft_atoi(++temp);
	temp = set_temp(temp, 'y');
	pos->y = 1.0f * ft_atoi(++temp);
	temp = set_temp(temp, 'z');
	pos->z = 1.0f * ft_atoi(++temp);
}

static void	set_light(t_env *env, char *temp, int i)
{
	temp = set_temp(++temp, 'r');
	env->obj.lights[i].intensity.r = ft_atoi(++temp);
	if (env->obj.lights[i].intensity.r != 0)
		env->obj.lights[i].intensity.r /= 255.0f;
	temp = set_temp(++temp, 'g');
	env->obj.lights[i].intensity.g = ft_atoi(++temp);
	if (env->obj.lights[i].intensity.g != 0)
		env->obj.lights[i].intensity.g /= 255.0f;
	temp = ft_strchr(++temp, 'b');
	env->obj.lights[i].intensity.b = ft_atoi(++temp);
	if (env->obj.lights[i].intensity.b != 0)
		env->obj.lights[i].intensity.b /= 255.0f;
}

void		fill_lights(t_env *env, int fd)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1 && i < env->obj.num_lights)
	{
		if (*line != '#')
		{
			temp = line;
			set_pos(&env->obj.lights[i].pos, temp);
			set_light(env, temp, i);
			i++;
		}
		free(line);
	}
}
