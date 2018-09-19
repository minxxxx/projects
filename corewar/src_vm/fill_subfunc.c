/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_subfunc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:56:37 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/18 09:13:22 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar_vm.h>

/*
**Set values for op_tab, LDI. STI, FORK
*/

void	fill_4(t_env *env)
{
	env->op_tab[LDI].name = "ldi";
	env->op_tab[LDI].nbr_args = 3;
	env->op_tab[LDI].type[0] = T_REG | T_DIR | T_IND;
	env->op_tab[LDI].type[1] = T_REG | T_DIR;
	env->op_tab[LDI].type[2] = T_REG;
	env->op_tab[LDI].code = LDI;
	env->op_tab[LDI].nbr_cycles = 25;
	env->op_tab[LDI].n_byte = TRUE;
	env->op_tab[STI].name = "sti";
	env->op_tab[STI].nbr_args = 3;
	env->op_tab[STI].type[0] = T_REG;
	env->op_tab[STI].type[1] = T_REG | T_DIR | T_IND;
	env->op_tab[STI].type[2] = T_REG | T_DIR;
	env->op_tab[STI].code = STI;
	env->op_tab[STI].nbr_cycles = 25;
	env->op_tab[STI].n_byte = TRUE;
	env->op_tab[FORK].name = "fork";
	env->op_tab[FORK].nbr_args = 1;
	env->op_tab[FORK].type[0] = T_DIR;
	env->op_tab[FORK].code = FORK;
	env->op_tab[FORK].nbr_cycles = 800;
	env->op_tab[FORK].n_byte = FALSE;
}

/*
**Set values for op_tab, LLD, LLDI, AFF
*/

void	fill_5_1(t_env *env)
{
	env->op_tab[AFF].name = "aff";
	env->op_tab[AFF].nbr_args = 1;
	env->op_tab[AFF].type[0] = T_REG;
	env->op_tab[AFF].code = AFF;
	env->op_tab[AFF].nbr_cycles = 2;
	env->op_tab[AFF].n_byte = TRUE;
}

void	fill_5(t_env *env)
{
	env->op_tab[LLD].name = "lld";
	env->op_tab[LLD].nbr_args = 2;
	env->op_tab[LLD].type[0] = T_DIR | T_IND;
	env->op_tab[LLD].type[1] = T_REG;
	env->op_tab[LLD].code = LLD;
	env->op_tab[LLD].nbr_cycles = 50;
	env->op_tab[LLD].n_byte = TRUE;
	env->op_tab[LLDI].name = "lldi";
	env->op_tab[LLDI].nbr_args = 3;
	env->op_tab[LLDI].type[0] = T_DIR | T_IND | T_REG;
	env->op_tab[LLDI].type[1] = T_DIR | T_REG;
	env->op_tab[LLDI].type[2] = T_REG;
	env->op_tab[LLDI].code = LLDI;
	env->op_tab[LLDI].nbr_cycles = 50;
	env->op_tab[LLDI].n_byte = TRUE;
	env->op_tab[LFORK].name = "lfork";
	env->op_tab[LFORK].nbr_args = 1;
	env->op_tab[LFORK].type[0] = T_DIR;
	env->op_tab[LFORK].code = LFORK;
	env->op_tab[LFORK].nbr_cycles = 1000;
	env->op_tab[LFORK].n_byte = FALSE;
	fill_5_1(env);
}
