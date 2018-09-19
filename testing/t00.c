/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 08:24:55 by khansman          #+#    #+#             */
/*   Updated: 2017/06/08 08:24:56 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/mman.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <unistd.h>
# include <pthread.h>

#include <stdio.h>

typedef struct			s_small_list
{
	unsigned short		used : 1;
	unsigned short		next : 15;
}						t_small_list;

int		main() {
	printf("Page Size: %d\n", getpagesize());
	printf("Size of small list struct: %d\n", (int)sizeof(t_small_list));
}
