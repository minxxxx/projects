/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 09:37:09 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/27 10:03:23 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static const char	*scan_flags(const char *off, t_flags *fl)
{
	while (is_pflag(*off) && *off)
	{
		if (!(fl->plus))
			fl->plus = (*off == '+');
		if (fl->ip == 0)
			fl->ip = (*off == '.');
		if (ft_isdigit(*off))
		{
			if (fl->ip)
			{
				fl->prec = ft_atoi(off);
				off += ft_strlen(ft_itoa(fl->prec));
			}
			else
			{
				fl->padding = ft_atoi(off);
				off += ft_strlen(ft_itoa(fl->padding));
			}
		}
		else
			off++;
	}
	return (off);
}

static t_flags		get_flags(const char *str, int *offset)
{
	t_flags		fl;
	const char	*off;

	fl = init_flags();
	fl.minus = (*str == '-');
	fl.hash = (*str == '#');
	fl.zero = (*str == '0' && fl.minus == 0 && fl.plus == 0);
	fl.space = (*str == ' ' && fl.plus == 0);
	off = str + (fl.minus || fl.hash || fl.zero || fl.space);
	off = scan_flags(off, &fl);
	*offset = off - str;
	fl.has_flags = (fl.minus || fl.plus || fl.zero || fl.hash
			|| fl.space || fl.prec);
	if (fl.zero && fl.ip == 0)
		fl.pad = '0';
	return (fl);
}

static t_mods		get_modifiers(const char *str, int *offset)
{
	int		i;
	t_mods	md;

	i = 0;
	md = init_mods();
	str += *offset;
	while (is_pmodifier(str[i]) && str[i] != '\0')
	{
		if (str[i] == 'z')
			md.zee++;
		if (str[i] == 'j')
			md.jay++;
		if (str[i] == 'l')
			md.ln++;
		if (str[i] == 'u')
			md.u_sign = 1;
		if (str[i] == 'h')
			md.sht++;
		i++;
	}
	md.has_mod = (md.ln || md.u_sign || md.sht || md.zee || md.jay);
	*offset -= (md.ln && md.u_sign && is_pnumeric(str[i]) == 0);
	*offset += i;
	return (md);
}

static int			get_type(const char *str, va_list *args, int *len)
{
	int		offset;
	t_mods	mods;
	t_flags	flags;
	char	*output;

	offset = 0;
	if (*str == '%')
	{
		ft_putchar('%');
		*len += 1;
		return (offset + 1);
	}
	flags = get_flags(str, &offset);
	if (*str != 'u')
		mods = get_modifiers(str, &offset);
	str += offset;
	if (mods.has_mod || *str == 'O' || *str == 'U' || *str == 'C')
		output = ft_check_mod(str, mods, args);
	else
		output = ft_check(str, mods, args);
	if (output)
		*len += ft_out(*str, output, flags);
	return (offset + 1);
}

int					ft_printf(const char *format, ...)
{
	const char		*trav;
	unsigned int	offset;
	va_list			arg;
	int				len;

	va_start(arg, format);
	len = 0;
	trav = format;
	while (*trav != '\0')
	{
		while (*trav != '%' && *trav)
		{
			ft_putchar(*trav++);
			len++;
		}
		if (*trav)
		{
			trav++;
			offset = get_type(trav, &arg, &len);
			trav += offset;
		}
	}
	va_end(arg);
	return (len);
}
