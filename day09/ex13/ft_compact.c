/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 09:46:37 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 13:43:22 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	size_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int	ftcompact(char **tab, int lenght)
{
	int i;
	int a;
	int b;

	i = 0;
	lenght = 0;
	while (tab[i])
	{
		if (tab[i] == 0)
		{
			b = 0;
			while (tab[i + b + 1])
			{
				a = 0;
				while (tab[i + b + 1][a])
				{
					tab[i + b][a] = tab[i + b + 1][a];
					a++;
				}
				b++;
			}
		}
		i++;
	}
	return (size_tab(tab));
}
