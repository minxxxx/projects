/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:56:10 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:57:16 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	printf("%s\n", ft_strrchr("abcdeabcde", 'a'));
	if( ft_strrchr("abcdeabcde", 'x') == NULL)
		printf("NULL\n");
	return EXIT_SUCCESS;
}
