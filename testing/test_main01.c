/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 08:39:11 by khansman          #+#    #+#             */
/*   Updated: 2017/06/13 08:39:13 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>

/*
** make && gcc ./malloc.so testing/test_main01.c && ./a.out
*/

int		main()
{
	void	*t00_tiny[10];
	void	*t00_small[10];
	void	*t00_large[3];

	for (int k = 0; k < 10; k++)
		t00_tiny[k] = malloc(10);
	for (int k = 0; k < 10; k++)
		t00_small[k] = malloc(200);
	for (int k = 0; k < 3; k++)
		t00_large[k] = malloc(100000);
	show_alloc_mem();
	for (int k = 0; k < 10; k++)
		free(t00_tiny[k]);
	for (int k = 0; k < 10; k++)
		free(t00_small[k]);
	for (int k = 0; k < 3; k++)
		free(t00_large[k]);
	return (0);
}
