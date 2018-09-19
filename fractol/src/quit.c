/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 09:23:28 by jbuys             #+#    #+#             */
/*   Updated: 2016/10/05 09:35:04 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		quit(char *str)
{
	ft_printf("\nError: %s\n", str);
	exit(EXIT_SUCCESS);
}

void		error_str(void)
{
	ft_printf("\n");
	ft_putendl("\033[1;34mAvailable Fractals are:\033[0m");
	ft_putendl("Mandelbrot");
	ft_putendl("Julia");
	ft_putendl("Burningship");
}
