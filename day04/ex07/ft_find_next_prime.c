/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 17:08:35 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/05 17:09:00 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		 return (nb);
	if (nb <= 2)
		return (2);
	if ((nb % 2) == 0)
		nb++;
	while (nb < (ft_recursive_power(2, 31)) - 1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb += 2;
	}
	return (-1);
}
