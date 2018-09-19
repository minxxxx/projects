/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 09:29:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/07/15 07:37:42 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	unknown_type(char c)
{
	ft_printf("Unknown type definition \"%c\"\n", c);
	exit(-1);
}

void	count_types(t_obj *temp, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (*line != '#' && *line != 'A')
		{
			if (*line == 'M')
				temp->num_mats++;
			else if (*line == 'L')
				temp->num_lights++;
			else if (*line == 'S')
				temp->num_spheres++;
			else if (*line == 'T')
				temp->num_tri++;
			else if (*line == 'C')
				temp->num_cyl++;
			else if (*line == 'O')
				temp->num_cone++;
			else
				unknown_type(*line);
		}
		free(line);
	}
}

void	val_types2(t_env *env, t_obj temp)
{
	if (temp.num_tri != OBJ.num_tri)
	{
		ft_printf("Error : Triangle count not equal to definitions.");
		exit(-1);
	}
	if (temp.num_cyl != OBJ.num_cyl)
	{
		ft_printf("Error : Material count not equal to definitions.");
		exit(-1);
	}
	if (temp.num_cone != OBJ.num_cone)
	{
		ft_printf("Error : Cone count not equal to definitions.");
		exit(-1);
	}
}

void	val_types(t_env *env, t_obj temp)
{
	if (temp.num_mats != OBJ.num_mats)
	{
		ft_printf("Error : Material count not equal to definitions.");
		exit(-1);
	}
	if (temp.num_lights != OBJ.num_lights)
	{
		ft_printf("Error : Light count not equal to definitions.");
		exit(-1);
	}
	if (temp.num_spheres != OBJ.num_spheres)
	{
		ft_printf("Error : Sphere count not equal to definitions.");
		exit(-1);
	}
	val_types2(env, temp);
}
