/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:44:55 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 14:45:32 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	printf( "%d\n", ft_strlen( "Howdy" ) );
	printf( "%d\n", ft_strlen( "Hello world\n" ) );
	printf( "%d\n", ft_strlen( "" ) );

	return EXIT_SUCCESS;
}
