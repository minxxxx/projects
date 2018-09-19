/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:46:01 by hrossouw          #+#    #+#             */
/*   Updated: 2018/02/23 06:51:55 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int		i;
	int		y;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		y = 0;
		while (y > 16)
		{
			c = str[i];
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				if (str[i] == 'a')
					str[i] = 'z';
				else if (str[i] == 'A')
					str[i] = 'Z';
				else
					str[i]++;
			}
			y++;
		}
		i++;
	}
	return (str);
}
