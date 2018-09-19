/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 13:57:50 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/08 14:11:04 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		conv(int nbr, char *base, int *nbr_f)
{
	int s_base;
	int i;

	i = 0;
	s_base = 0;
	while (base[s_base])
		s_base++;
	while (nbr)
	{
		nbr_f[i] = nbr % s_base;
		nbr = nbr / s_base;
		i++;
	}
	return (i);
}

unsigned int	ft_active_bits(int value)
{
	int				nbr_f[100];
	int				i;
	int				neg;
	unsigned int	actv_bits;
	char			base[] = "01";

	i = 0;
	neg = 0;
	actv_bits = 0;
	if (value < 0)
	{
		neg = 1;
		value = -value;
	}
	i = conv(value, base, nbr_f);
	while (--i >= 0)
		actv_bits = actv_bits + (base[nbr_f[i] - 48);
	if (neg == 1)
		return (32 - actv_bits + 1);
	return (actv_bits);
}
