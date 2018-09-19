/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_memccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:33:54 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 11:34:45 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char* msg = "This is the string: not copied";

int main( void )
{
	char buffer[80];

	ft_memset( buffer, '\0', 80 );
	ft_memccpy( buffer, msg, ':', 80 );

	printf( "%s\n", buffer );

	return EXIT_SUCCESS;
}
