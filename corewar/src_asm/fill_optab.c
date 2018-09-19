/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_optab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 11:57:54 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:20:53 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** Fills the optab for later use, norme friendly as opposed to the old op_tab
*/

void	a_fill_1(t_info *env)
{
	env->op_tab[0].name = "0";
	env->op_tab[0].nbr_args = 0;
	ft_memcpy(&env->op_tab[0].type, "0", 2);
	env->op_tab[0].code = 0;
	env->op_tab[0].nbr_cycles = 0;
	env->op_tab[LIVE].name = "live";
	env->op_tab[LIVE].nbr_args = 1;
	env->op_tab[LIVE].type[0] = T_DIR;
	env->op_tab[LIVE].code = LIVE;
	env->op_tab[LIVE].nbr_cycles = 10;
	env->op_tab[LIVE].n_byte = FALSE;
	env->op_tab[LD].name = "ld";
	env->op_tab[LD].nbr_args = 2;
	env->op_tab[LD].type[0] = T_DIR | T_IND;
	env->op_tab[LD].type[1] = T_REG;
	env->op_tab[LD].code = LD;
	env->op_tab[LD].nbr_cycles = 5;
	env->op_tab[LD].n_byte = TRUE;
	env->op_tab[ST].name = "st";
	env->op_tab[ST].nbr_args = 2;
	env->op_tab[ST].type[0] = T_REG;
	env->op_tab[ST].type[1] = T_REG | T_IND;
	env->op_tab[ST].code = ST;
	env->op_tab[ST].nbr_cycles = 5;
	env->op_tab[ST].n_byte = TRUE;
}

void	a_fill_2(t_info *env)
{
	env->op_tab[ADD].name = "add";
	env->op_tab[ADD].nbr_args = 3;
	env->op_tab[ADD].type[0] = T_REG;
	env->op_tab[ADD].type[1] = T_REG;
	env->op_tab[ADD].type[2] = T_REG;
	env->op_tab[ADD].code = ADD;
	env->op_tab[ADD].nbr_cycles = 10;
	env->op_tab[ADD].n_byte = TRUE;
	env->op_tab[SUB].name = "sub";
	env->op_tab[SUB].nbr_args = 3;
	env->op_tab[SUB].type[0] = T_REG;
	env->op_tab[SUB].type[1] = T_REG;
	env->op_tab[SUB].type[2] = T_REG;
	env->op_tab[SUB].code = SUB;
	env->op_tab[SUB].nbr_cycles = 10;
	env->op_tab[SUB].n_byte = TRUE;
	env->op_tab[AND].name = "and";
	env->op_tab[AND].nbr_args = 3;
	env->op_tab[AND].type[0] = T_REG | T_DIR | T_IND;
	env->op_tab[AND].type[1] = T_REG | T_DIR | T_IND;
	env->op_tab[AND].type[2] = T_REG;
	env->op_tab[AND].code = AND;
	env->op_tab[AND].nbr_cycles = 6;
	env->op_tab[AND].n_byte = TRUE;
}

/*
** Set values for op_tab, OR. XOR, ZJMP
*/

void	a_fill_3(t_info *env)
{
	env->op_tab[OR].name = "or";
	env->op_tab[OR].nbr_args = 3;
	env->op_tab[OR].type[0] = T_REG | T_DIR | T_IND;
	env->op_tab[OR].type[1] = T_REG | T_DIR | T_IND;
	env->op_tab[OR].type[2] = T_REG;
	env->op_tab[OR].code = OR;
	env->op_tab[OR].nbr_cycles = 6;
	env->op_tab[OR].n_byte = TRUE;
	env->op_tab[XOR].name = "xor";
	env->op_tab[XOR].nbr_args = 3;
	env->op_tab[XOR].type[0] = T_REG | T_DIR | T_IND;
	env->op_tab[XOR].type[1] = T_REG | T_DIR | T_IND;
	env->op_tab[XOR].type[2] = T_REG;
	env->op_tab[XOR].code = XOR;
	env->op_tab[XOR].nbr_cycles = 6;
	env->op_tab[XOR].n_byte = TRUE;
	env->op_tab[ZJMP].name = "zjmp";
	env->op_tab[ZJMP].nbr_args = 1;
	env->op_tab[ZJMP].type[0] = T_DIR;
	env->op_tab[ZJMP].code = ZJMP;
	env->op_tab[ZJMP].nbr_cycles = 20;
	env->op_tab[ZJMP].n_byte = FALSE;
}

/*
** Poor planninge led to this as a normified function. oops
** It sets the dir_as_index values
*/

void	set_dai(t_info *env)
{
	env->op_tab[LIVE].dir_as_index = FALSE;
	env->op_tab[LD].dir_as_index = FALSE;
	env->op_tab[ST].dir_as_index = FALSE;
	env->op_tab[ADD].dir_as_index = FALSE;
	env->op_tab[SUB].dir_as_index = FALSE;
	env->op_tab[AND].dir_as_index = FALSE;
	env->op_tab[OR].dir_as_index = FALSE;
	env->op_tab[XOR].dir_as_index = FALSE;
	env->op_tab[ZJMP].dir_as_index = TRUE;
	env->op_tab[LDI].dir_as_index = TRUE;
	env->op_tab[STI].dir_as_index = TRUE;
	env->op_tab[FORK].dir_as_index = TRUE;
	env->op_tab[LLD].dir_as_index = FALSE;
	env->op_tab[LLDI].dir_as_index = TRUE;
	env->op_tab[LFORK].dir_as_index = TRUE;
	env->op_tab[AFF].dir_as_index = FALSE;
}

/*
** Sets values in the op_tab - a really ugly way of doing but very useful.
*/

void	a_fill_op_tab(t_info *env)
{
	a_fill_1(env);
	a_fill_2(env);
	a_fill_3(env);
	a_fill_4(env);
	a_fill_5(env);
	set_dai(env);
}
