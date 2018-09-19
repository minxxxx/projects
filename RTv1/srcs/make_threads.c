/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 10:11:28 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/09/01 14:27:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	make_threads(t_env *env)
{
	t_rt_thread	bounds[NO_THREADS];
	pthread_t	thread_id[NO_THREADS];
	int			i;
	t_env		e[NO_THREADS];
	int			d;

	d = -1;
	while (++d < 4)
		e[d] = *env;
	i = -1;
	PROGRESS = 0;
	bounds[0] = (t_rt_thread){1, &PROGRESS, 0, WIN_X, 0, WIN_Y / 4, &e[0]};
	bounds[1] = (t_rt_thread){2, &PROGRESS, 0, WIN_X, WIN_Y / 4,
		WIN_Y / 4 * 2, &e[1]};
	bounds[2] = (t_rt_thread){3, &PROGRESS, 0, WIN_X, WIN_Y / 4 * 2,
		WIN_Y / 4 * 3, &e[2]};
	bounds[3] = (t_rt_thread){4, &PROGRESS, 0, WIN_X, WIN_Y / 4 * 3,
		WIN_Y, &e[3]};
	while (++i < NO_THREADS)
		pthread_create(&thread_id[i], NULL, raytrace, &bounds[i]);
	i = -1;
	while (++i < NO_THREADS)
		pthread_join(thread_id[i], NULL);
}
