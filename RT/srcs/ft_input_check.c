/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:14:53 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 11:00:00 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int		ft_input_error(char *obj, char *msg)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(obj, 2);
	ft_putstr_fd(" => ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(-1);
}

int		ft_val_col(t_col *col)
{
	if (col->r < 0 || col->r > 255)
		return (-1);
	if (!(col->g >= 0 && col->g <= 255))
		return (-1);
	if (!(col->b >= 0 && col->b <= 255))
		return (-1);
	return (1);
}

int		ft_val_mat(t_env *env, int mat, char *obj)
{
	if (mat > OBJ.num_mats || mat < 0)
		return (ft_input_error(obj, "Material out of bounds."));
	return (1);
}
