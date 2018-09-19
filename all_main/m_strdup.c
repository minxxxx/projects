/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:58:42 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 13:53:11 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	char *dup;

	dup = ft_strdup( "Make a copy" );
	printf( "%s\n", dup );
	free (dup);

	return EXIT_SUCCESS;
}
