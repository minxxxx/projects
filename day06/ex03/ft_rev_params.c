/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:54:20 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/07 18:07:11 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	main(int argc, char **argv)
{
	int i;
	int g;

	i = argc - 1;
	g = 0;
	while (i > 0)
	{
		while (argv[i][g])
		{
			ft_putchar(argv[i][g]);
			g++;
		}
		ft_putchar('\n');
		g = 0;
		i--;
	}
	return (0);
}
