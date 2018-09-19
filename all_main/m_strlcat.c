/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strlcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 12:05:49 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:35:21 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	char src[30] , dest[40];
	int l;

	ft_strcpy(src, "the source");
	ft_strcpy(dest, "the destination of this");

	ft_strlcat(dest, src, l);

	printf("final: %s", dest);
	return (0);
}
