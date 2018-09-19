/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_memcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:43:46 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 11:44:48 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main ()
{
	char str1[15];
	char str2[15];
	int ret;

	ft_memcpy(str1, "abcdef", 6);
	ft_memcpy(str2, "ABCDEF", 6);

	ret = ft_memcmp(str1, str2, 5);

	if(ret > 0)
	{
		printf("str2 is less than str1");
	}
	else if(ret < 0) 
	{
		printf("str1 is less than str2");
	}
	else 
	{
		printf("str1 is equal to str2");
	}

	return(0);
}
