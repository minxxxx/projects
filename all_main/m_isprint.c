/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:56:25 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 14:57:42 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char the_chars[] = { 'A', 0x09, ' ', 0x7d };

#define SIZE sizeof( the_chars ) / sizeof( char )

int main( void )
{
	int i;

	for( i = 0; i < SIZE; i++ ) {
		if( ft_isprint( the_chars[i] ) ) {
			printf( "Char %c is a printable character\n",
					the_chars[i] );
		} else {
			printf( "Char %c is not a printable character\n",
					the_chars[i] );
		}
	}

	return EXIT_SUCCESS;
}
