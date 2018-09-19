/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 14:41:25 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/06/05 08:01:54 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_w(char *str, int *w, int inc)
{
	ft_putstr(str);
	*w += inc;
}

t_mods	init_mods(void)
{
	t_mods	md;

	md.ln = 0;
	md.u_sign = 0;
	md.sht = 0;
	md.zee = 0;
	md.jay = 0;
	md.has_mod = 0;
	return (md);
}

char	*ft_check(const char *str, t_mods md, va_list *args)
{
	char	*out;

	out = ft_strnew(sizeof(char) * 2);
	if (*str == 'c')
	{
		*out = (char)va_arg(*args, int);
		return (out);
	}
	if (*str == 's' || *str == 'S')
		return (va_arg(*args, char*));
	if ((*str == 'i' || *str == 'd') && md.has_mod == 0)
		return (ft_itoa(va_arg(*args, int)));
	if (*str == 'u')
		return (convert_uns(va_arg(*args, int), 10, 0));
	if (*str == 'o')
		return (convert(va_arg(*args, unsigned int), 8, 0));
	if (*str == 'x')
		return (convert(va_arg(*args, int), 16, 0));
	if (*str == 'X')
		return (convert(va_arg(*args, int), 16, 1));
	if (*str == 'p')
		return (convert_uns((unsigned long)va_arg(*args, void*), 16, 0));
	return (NULL);
}

char	*ft_check_mod(const char *str, t_mods md, va_list *args)
{
	if (((*str == 'd' || *str == 'i') && md.ln == 1) || *str == 'D')
		return (convert(va_arg(*args, long int), 10, 0));
	if ((*str == 'd') && md.ln == 2 && md.u_sign == 0)
		return (convert(va_arg(*args, long long int), 10, 0));
	if ((*str == 'u' && md.ln == 1 && md.u_sign) || *str == 'U')
		return (convert_uns_l(va_arg(*args, unsigned long int), 10, 0));
	if (*str == 'u' && md.ln == 2 && md.u_sign)
		return (convert_uns_l((unsigned long)va_arg(*args, ULL_INT), 10, 0));
	if (*str == 'i' && md.sht)
		return (convert(va_arg(*args, int), 10, 0));
	if (*str == 'i' && md.u_sign)
		return (convert_uns(va_arg(*args, unsigned int), 10, 0));
	if ((md.zee && (*str == 'd' || *str == 'i')))
		return (convert(va_arg(*args, unsigned int), 10, 0));
	if (md.jay && is_psigned(*str))
		return (convert(va_arg(*args, LL_INT), 10, 0));
	if ((*str == 'O') || (*str == 'o' && md.ln == 1))
		return (convert_uns_l(va_arg(*args, unsigned long int), 8, 0));
	if (*str == 'C' || (*str == 'c' && md.ln))
		return (va_arg(*args, char*));
	return (NULL);
}
