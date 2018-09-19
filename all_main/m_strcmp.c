/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:29:48 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 14:32:16 by lmucassi         ###   ########.fr       */
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


	ft_strcpy(str1, "abcdef");
	ft_strcpy(str2, "ABCDEF");

	ret = ft_strcmp(str1, str2);

	if(ret < 0)
	{
		printf("str1 is less than str2");
	}
	else if(ret > 0) 
	{
		printf("str2 is less than str1");
	}
	else 
	{
		printf("str1 is equal to str2");
	}

	return(0);
}
