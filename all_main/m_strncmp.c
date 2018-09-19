/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:33:39 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 14:36:21 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main( void )
{
	printf("%d\n", ft_strncmp("abcdef", "abcDEF", 10));
	printf("%d\n", ft_strncmp("abcdef", "abcDEF",  6));
	printf("%d\n", ft_strncmp("abcdef", "abcDEF",  3));
	printf("%d\n", ft_strncmp("abcdef", "abcDEF",  0));
	return EXIT_SUCCESS;
}
