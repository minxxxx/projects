/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:18:52 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/04 11:22:39 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int	i;
	int	t;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			t = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = t;
			i = 0;
		}
		else
			i++;
	}
}
