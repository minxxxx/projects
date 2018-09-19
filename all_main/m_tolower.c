/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tolower.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:03:44 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 15:04:27 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char chars[] = {
	'A',
	'5',
	'$',
	'Z'
};

#define SIZE sizeof( chars ) / sizeof( char )

int main( void )
{
	int   i;

	for( i = 0; i < SIZE; i++ ) {
		printf( "%c ", ft_tolower( chars[ i ] ) );
	}
	printf( "\n" );
	return EXIT_SUCCESS;
}
