/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:15:24 by acazuc            #+#    #+#             */
/*   Updated: 2015/12/28 09:37:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	unsigned char ch;

	ch = (unsigned char)c;
	return (ch == c && ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
			|| (ch >= '0' && ch <= '9')));
}
