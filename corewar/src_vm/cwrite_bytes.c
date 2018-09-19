/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwrite_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 07:49:41 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 12:02:39 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

void	cwrite_bytes(t_env *env, int start, char *to_write, size_t write_size)
{
	size_t	i;
	size_t	b;

	i = start;
	b = 0;
	while (b < write_size)
	{
		if (i >= MEM_SIZE)
			i = 0;
		env->memory[i] = to_write[b];
		i++;
		b++;
	}
}
