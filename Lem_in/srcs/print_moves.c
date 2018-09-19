/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:14:26 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/22 16:27:54 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*get_best_move(t_room *room)
{
	t_room_list	*lst;
	t_room		*bestmove;

	bestmove = NULL;
	lst = room->links;
	while (lst)
	{
		if (!bestmove || bestmove->point > lst->room->point)
			bestmove = lst->room;
		lst = lst->next;
	}
	return (bestmove);
}

void			print_moves(t_env *env)
{
	t_room		*current;

	while (env->ants > 0)
	{
		current = env->start;
		while (current != env->end)
		{
			ft_putstr("\033[0;35m");
			current = get_best_move(current);
			ft_putchar('L');
			ft_putnbr(env->total_ants + 1 - env->ants);
			ft_putchar('-');
			ft_putendl(current->name);
			ft_putstr("\033[1;37m\033[0;37m");
		}
		env->ants--;
	}
}
