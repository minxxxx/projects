/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 11:35:24 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/02 15:47:46 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct	s_env
{
	int			*stack_a;
	int			stack_a_size;
	int			*stack_b;
	int			stack_b_size;
	int			*sorted;
	int			sorted_size;
	int			min;
	int			max;
	int			count;
	int			pre_sort;
}				t_env;

#endif
