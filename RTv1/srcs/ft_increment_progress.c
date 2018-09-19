/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_progress.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:04:45 by oexall            #+#    #+#             */
/*   Updated: 2016/09/01 14:27:41 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	ft_increment_progress(t_rt_thread *t)
{
	pthread_mutex_t	mutex;
	double			prog;

	prog = *(t->progress);
	prog = prog / (WIN_Y / 10);
	prog *= 100;
	pthread_mutex_lock(&mutex);
	*(t->progress) += 1;
	ft_putnbr((int)prog);
	ft_putstr("%\n");
	pthread_mutex_unlock(&mutex);
}
