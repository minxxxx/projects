/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_memalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:39:31 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/22 17:35:54 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char *str;

	str = (char *) ft_memalloc(15);
	ft_strcpy(str, "tutorialspoint");
	printf("String = %s,  Address = %s\n", str, str);

	str = (char *) realloc(str, 25);
	strcat(str, ".com");
	printf("String = %s,  Address = %s\n", str, str);

	free(str);

	return(0);
}
