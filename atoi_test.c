/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 16:01:34 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/30 16:09:35 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	int i;
	i = ft_atoi("999999999999999999999999999999999");
	printf("%d\n", i);
	return (0);
}