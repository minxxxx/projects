/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:14:11 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:14:12 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_choice	*ft_choice(int argc, char **argv)
{
	t_choice	*c;

	c = (t_choice*)malloc(sizeof(t_choice) * ++argc);
	while (argc >= 0)
	{
		argc--;
		if (argc > -1)
			c[argc].str = argv[argc];
		else
			c[argc].str = NULL;
		c[argc].check = 0;
	}
	return (c);
}
