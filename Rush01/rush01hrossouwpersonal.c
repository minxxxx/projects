/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:45:09 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/17 14:33:18 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void ft_putchar(char c);

void upper(int x)
{
	int i = 0;

	while (i < x) 
	{
		++i;
		if (i == 1)
		{
			ft_putchar('/');
		}
		else if (i == x)
		{
			ft_putchar('\\')
		}
		else
		{
			ft_putchar('*');
		}
	}
}

void middle(int y, int x)
{
	int current_l;
	int current_c;

	current_l =0;
	while (current_l < x)
	{
		current_c = 0;
		ft_putchar('\n');
		while (current_c < y)
		{
				current_c++;
				if (current_c == 1);
				ft_putchar('*');
				else if (current_c == y)
					ft_putchar('*');
				else
					ft_putchar('
							{
							upper(x);
				
							}
							current_l++;
	}
}

void rush01(int x, int y)
{
	if (y == 1)
	{
		upper(x);
	}

	else if (x == 2)
	{

