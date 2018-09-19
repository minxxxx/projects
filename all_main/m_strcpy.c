/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:49:16 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:50:48 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	char buffer[80];

	ft_strcpy( buffer, "Hello " );
	ft_strcat( buffer, "world" );

	printf( "%s\n", buffer );

	return EXIT_SUCCESS;
}
