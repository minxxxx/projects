/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 16:11:11 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/28 18:02:42 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrev(char *str)
{
	int		i;
	int		limit;
	char	temp;

	limit = ft_strlen(str);
	i = -1;
	while (++i < --limit)
	{
		temp = str[i];
		str[i] = str[limit];
		str[limit] = temp;
	}
	return (str);
}

static int		ft_sanity_check(int n)
{
	int i;

	i = 1;
	if (n < 0)
		i *= -1;
	return (i);
}

static char		*ft_creating_space(int n, int neg, int i)
{
	char	*str;
	int		num;

	num = (n * neg);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	str = ft_strnew(i);
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		num;
	int		neg;

	i = 0;
	if ((neg = ft_sanity_check(n)) == -1)
		i++;
	num = (neg * n);
	str = ft_creating_space(n, neg, i);
	n = n * neg;
	i = 0;
	while (n > 0)
	{
		str[i] = ((n % 10) + '0');
		n /= 10;
		i++;
	}
	if (neg == -1)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
