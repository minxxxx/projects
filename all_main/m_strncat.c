/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strncat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:02:21 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:03:00 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main ()
{
	char src[50], dest[50];

	ft_strcpy(src,  "This is source");
	ft_strcpy(dest, "This is destination");

	ft_strncat(dest, src, 15);

	printf("Final destination string : |%s|", dest);

	return(0);
}
