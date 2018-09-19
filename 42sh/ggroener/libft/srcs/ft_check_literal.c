/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_literal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 10:26:35 by ggroener          #+#    #+#             */
/*   Updated: 2016/08/07 13:34:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_check_literal2(char a, char b)
{
	if (a != 92)
		return (32);
	if (b == 92)
		return ('\\');
	if (b == '0')
		return ('\0');
	if (b == 't')
		return ('t');
	if (b == 39)
		return (39);
	if (b == 34)
		return (34);
	if (b == 'a')
		return ('a');
	if (b == 'b')
		return ('b');
	if (b == 'f')
		return ('f');
	if (b == 'n')
		return ('n');
	if (b == 'r')
		return ('r');
	if (b == 'v')
		return ('v');
	return (32);
}

char	ft_check_literal(char a, char b, char c)
{
	if (a == 92 && b == 92)
	{
		if (c == 't')
			return ('\t');
		if (c == 39)
			return ('\'');
		if (c == 34)
			return ('\"');
		if (c == 'a')
			return ('\a');
		if (c == 'b')
			return ('\b');
		if (c == 'f')
			return ('\f');
		if (c == 'n')
			return ('\n');
		if (c == 'r')
			return ('\r');
		if (c == 'v')
			return ('\v');
	}
	return (32);
}
