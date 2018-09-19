/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isascii.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:37:50 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:39:51 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char the_chars[] = { 'A', 0x80, 'Z' };
#define SIZE sizeof( the_chars ) / sizeof( char )

int main( void )
{
	int i;

	for( i = 0; i < SIZE; i++ ) {
		if( ft_isascii(the_chars[i])) {
			printf( "Char %c is an ASCII character\n",
					the_chars[i] );
		} else {
			printf( "Char %c is not an ASCII character\n",
					the_chars[i] );
		}
	}

	return EXIT_SUCCESS;
}
