/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 09:12:12 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/18 08:58:53 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Returns the type of parameter
*/

int	check_param(char *param)
{
	if (param[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else if (param[0] == 'r')
		return (REG_CODE);
	else
		return (IND_CODE);
}
