/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 08:56:39 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/19 11:38:51 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** calls functions for file validation
*/

void	validate_input(t_info *info)
{
	check_nc(info);
	init_header(&(info->header), info);
}
