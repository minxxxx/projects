/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:53:35 by khansman          #+#    #+#             */
/*   Updated: 2017/06/14 09:53:36 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*calloc(size_t count, size_t size)
{
	size_t		total_size;
	void		*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	ft_bzero(ptr, total_size);
	return (ptr);
}
