/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_strstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmucassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:21:45 by lmucassi          #+#    #+#             */
/*   Updated: 2017/07/21 12:25:20 by lmucassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int main()
{
	const char haystack[20] = "TutorialsPoint";
	const char needle[10] = "Point";
	char *ret;

	ret = ft_strstr(haystack, needle);

	printf("The substring is: %s\n", ret);

	return(0);
}
