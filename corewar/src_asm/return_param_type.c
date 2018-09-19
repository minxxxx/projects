/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_param_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 13:48:06 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:33:34 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Returns the correct param code for the given parameter
*/

t_arg_type	return_param_type(char *param)
{
	if (param[0] == DIRECT_CHAR)
		return (T_DIR);
	else if (param[0] == 'r')
		return (T_REG);
	else
		return (T_IND);
}
