/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 11:00:08 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/05 16:51:21 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*get_str(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (ptr[i] != '\0')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	long int	num;
	char		buf[50];
	char		*ptr;
	int			neg;

	num = n;
	ptr = &buf[49];
	*ptr = '\0';
	neg = 0;
	if (num < 0)
	{
		num *= -1;
		neg = 1;
	}
	while (num > 0)
	{
		*--ptr = "0123456789"[num % 10];
		num = num / 10;
	}
	if (neg == 1)
		*--ptr = '-';
	return (get_str(ptr));
}
