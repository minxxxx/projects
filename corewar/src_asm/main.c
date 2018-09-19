/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:55:31 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/25 15:18:32 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int	main(int argc, char **argv)
{
	t_info	info;

	info.commands = NULL;
	if (error_check(argc, argv) == -1)
		return (0);
	info.file_name = argv[1];
	store_input(&info, argv[1]);
	validate_input(&info);
	start_compile(&info);
	write_file(&info);
	ft_printf("Assembling champion!\n\t%s\n\t%s\n", info.header.prog_name,
			info.header.comment);
	free_input(&info);
	free_info_label(&info);
	exit(0);
}
