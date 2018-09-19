/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 17:05:08 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/05 17:05:29 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int result;

	result = 1;
	if ((nb == 0 && power !=0 || power < 0))
		return (0);
	if ((power == 0) || ((nb < 0) && (power == 0)))
			return (1);
	else
	{
	while (power > 0)
		{
			result = nb * result;
			power--;
		}
		return (result);
	}
}
