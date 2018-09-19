/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 11:07:00 by khansman          #+#    #+#             */
/*   Updated: 2016/09/11 12:59:38 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static void	neg_case(char **str, unsigned int *k, long int *num, int base)
{
	if (*num < 0)
	{
		*num *= -1;
		if (base == 10)
		{
			*str[*k] = '-';
			(*k)++;
		}
	}
}

char		*ft_itoa_base(int value, int base)
{
	t_base_var	var;

	BASE_STR;
	var.num = value;
	var.ba = base;
	var.k = 0;
	var.l = 1;
	if ((var.str = (char *)malloc(40)) == NULL)
		return (NULL);
	if (base < 2 || base > 16)
		return (NULL);
	neg_case(&var.str, &var.k, &var.num, base);
	while ((var.num / (var.l)) >= base)
		var.l *= base;
	while (var.l > 0)
	{
		var.str[var.k] = b[((var.num / var.l) % var.ba)];
		var.num -= (var.num / var.l) * var.l;
		var.k++;
		if (var.l == 1)
			var.l = 0;
		var.l = var.l / base;
	}
	var.str[var.k] = '\0';
	return (var.str);
}
