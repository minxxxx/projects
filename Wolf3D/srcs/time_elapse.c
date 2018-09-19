/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_elapse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 07:39:22 by khansman          #+#    #+#             */
/*   Updated: 2016/06/23 07:39:26 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

long	time_elapse(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
