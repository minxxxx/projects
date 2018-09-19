/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:52:11 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:54:20 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	char buffer[80];
	char* where;

	ft_strcpy( buffer, "video x-rays" );

	where = ft_strchr( buffer, 'x' );

	if( where == NULL ) {
		printf( "'x' not found\n" );
	} else {
		printf( "'x' found in: %s\n", where );
	}

	return EXIT_SUCCESS;
}
