/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isalnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:47:29 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 14:51:04 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	if( ft_isalnum( getchar() ) ) {
		printf( "That's alpha-numeric!\n" );
	}
	else
		printf("not alpha-numeric");

	return EXIT_SUCCESS;
}
