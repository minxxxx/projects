/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 09:02:57 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/27 09:57:10 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*convert(long int num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_uns(unsigned int num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}

char	*convert_uns_l(unsigned long long num, int base, int hex_upper)
{
	static char	buffer[50];
	char		*ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	while (num != 0)
	{
		if (hex_upper)
			*--ptr = "0123456789ABCDEF"[num % base];
		else
			*--ptr = "0123456789abcdef"[num % base];
		num /= base;
	}
	return (ptr);
}
