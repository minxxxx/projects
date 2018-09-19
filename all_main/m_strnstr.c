/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strnstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:22:14 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:26:29 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main ()
{
	const char dest[20] = "oldstringofme";
	const char src[10]  = "ringo";
	char *ret;
	int n = 7;

	ret = ft_strnstr(dest, src, n);
	printf("The string is %s\n", ret);

	return(0);
}
