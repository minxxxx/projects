/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:17:51 by khansman          #+#    #+#             */
/*   Updated: 2017/06/09 08:17:53 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	malloc_error_quit(char *error_message)
{
	ft_putstr("MALLOC ERROR: ");
	ft_putendl(error_message);
	exit(0);
}
