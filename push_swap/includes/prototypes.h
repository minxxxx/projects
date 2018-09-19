/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 11:52:38 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/03 11:48:58 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "env.h"

void	parse_args(t_env *env, int ac, char **av);
void	check_dur(t_env *env);
int		valid_int(int ac, char **av);
int		is_sorted(t_env *env);
void	error_quit(char *str);
void	calc_sorted(t_env *env);
void	pre_sort(t_env *env);
int		idiot_proof(int ac, char **av);
void	sort(t_env *env);
void	sort_3(t_env *env);
void	sort_5(t_env *env);
void	print_a(t_env *env);
void	print_b(t_env *env);
void	sa(t_env *env);
void	sb(t_env *env);
void	ss(t_env *env);
void	pa(t_env *env);
void	pb(t_env *env);
void	ra(t_env *env);
void	rb(t_env *env);
void	rr(t_env *env);
void	rra(t_env *env);
void	rrb(t_env *env);
void	rrr(t_env *env);

#endif
