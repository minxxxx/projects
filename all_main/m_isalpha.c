/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isalpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:52:27 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 14:53:57 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	if( ft_isalpha( getchar() ) ) {
		printf( "That's alphabetic\n" );
	}
	else
		printf("not an alphabet");

	return EXIT_SUCCESS;
}
