/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 19:22:20 by mlubisi           #+#    #+#             */
/*   Updated: 2016/04/07 19:31:38 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_lowercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] >= 'k')
				str[i] -= 10;
			else
				str[i] += 16;
		}
		i++;
	}
	return (str);
}

char	*ft_uppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] >= 'K')
				str[i] -= 10;
			else
				str[i] += 16;
		}
		i++;
	}
	return (0);
}

char	*ft_rot42(char *str)
{
	ft_lowercase(str);
	ft_uppercase(str);
	return (str);
}
