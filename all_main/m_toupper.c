/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_toupper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:09:14 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 15:10:06 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char chars[] = {
	'a',
	'5',
	'$',
	'z'
};

#define SIZE sizeof( chars ) / sizeof( char )

int main( void )
{
	int   i;

	for( i = 0; i < SIZE; i++ ) {
		printf( "%c ", ft_toupper( chars[ i ] ) );
	}
	printf( "\n" );
	return EXIT_SUCCESS;
}
