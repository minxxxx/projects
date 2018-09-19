/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:22:26 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/11 14:22:29 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

int	my_strlen(char *str)
{
    int	i;
    
    i = 0;
    while (str[i])
        ++i;
    return (i);
}

void	my_put_nbr(int nbr)
{
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
        a = l + '0';
        //ft_putchar(l + '0');
        ft_putchar(str[i]);
        write(1, &a, 1);
    }
    if (nbr > 9)
    {
        my_put_nbr(nbr / 10);
        my_put_nbr(nbr % 10);
    }
    else
        ft_putchar(nbr + 48);
}