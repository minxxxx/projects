/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strncpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:41:47 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:43:41 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	char buffer[15];

	printf( "%s\n", ft_strncpy( buffer, "abcdefg", 10 ) );
	printf( "%s\n", ft_strncpy( buffer, "1234567",  6 ) );
	printf( "%s\n", ft_strncpy( buffer, "abcdefg",  3 ) );
	printf( "%s\n", ft_strncpy( buffer, "*******",  0 ) );
	return EXIT_SUCCESS;
}
