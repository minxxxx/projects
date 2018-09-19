/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isdigit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 15:28:20 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 15:29:59 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char the_chars[] = { 'A', '5', '$' };

#define SIZE sizeof( the_chars ) / sizeof( char )

int main( void )
{
	int i;

	for( i = 0; i < SIZE; i++ ) {
		if( ft_isdigit( the_chars[i] ) ) {
			printf( "Char %c is a digit character\n",
					the_chars[i] );
		} else {
			printf( "Char %c is not a digit character\n",
					the_chars[i] );
		}
	}

	return EXIT_SUCCESS;
}
