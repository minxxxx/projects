/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:14:26 by hrossouw          #+#    #+#             */
/*   Updated: 2018/03/04 13:49:40 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int i;

	i = 1;

	while(i <= 100)
	{
		if(((i % 3) == 0) && ((i % 5) == 0))
			printf("%d FizzBuzz", i);
		else if ((i % 3) == 0)
			printf("%d Fizz", i);
		else if ((i % 5) == 0)
			printf("%d Buzz", i);
		else
			printf("%d", i);
		i++;
		printf("\n");
	}
	return (0);
}
