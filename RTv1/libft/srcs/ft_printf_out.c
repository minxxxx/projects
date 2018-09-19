/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddu-toit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 09:16:46 by ddu-toit          #+#    #+#             */
/*   Updated: 2016/05/27 10:03:44 by ddu-toit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_out_prec(char type, t_flags fl, int len)
{
	int	w;

	w = 0;
	if (fl.prec)
	{
		while (len + w < fl.prec && is_pnumeric(type) && type != 'f')
		{
			ft_putchar('0');
			w++;
		}
		return (w);
	}
	return (0);
}

static int	ft_out_sprec(char type, char *str, t_flags fl)
{
	int	i;

	i = 0;
	if (fl.prec && type == 's')
	{
		while (i < fl.prec)
			ft_putchar(str[i++]);
	}
	else
	{
		while (str[i])
			ft_putchar(str[i++]);
	}
	return (i);
}

static int	ft_padstr(char type, char *out, t_flags fl, int len)
{
	int	w;
	int	i;

	w = 0;
	if (fl.ip == 1 && fl.prec == 0 && type == 's')
		len = 0;
	i = len;
	while (fl.minus && out[w] && (type != 's'))
		ft_putchar(out[w++]);
	while (type == 's' && w < fl.prec && out[w] && fl.prec && fl.minus)
		ft_putchar(out[w++]);
	while (i < fl.padding)
	{
		ft_putchar(fl.pad);
		i++;
	}
	while (fl.minus == 0 && out[w] && type != 's')
		ft_putchar(out[w++]);
	while (type == 's' && w < fl.prec && out[w] && fl.prec && !fl.minus)
		ft_putchar(out[w++]);
	return (w + i - len);
}

static int	ft_prefix(char type, char *out, t_flags fl)
{
	int	w;

	w = 0;
	if (type == 'X' && fl.hash)
		ft_putstr_w("0X", &w, 2);
	if (type == 'x' && fl.hash)
		ft_putstr_w("0x", &w, 2);
	if (type == 'p')
		ft_putstr_w("0x7fff", &w, 6);
	if (is_psigned(type) && ft_atoi(out) > 0 && fl.plus)
		ft_putstr_w("+", &w, 1);
	if (is_psigned(type) && fl.space && fl.plus == 0)
		ft_putstr_w(" ", &w, 1);
	if ((type == 'o' || type == 'O') && fl.hash)
		ft_putstr_w("0", &w, 1);
	return (w);
}

int			ft_out(char type, char *out, t_flags fl)
{
	int		len;
	int		w;

	len = ft_strlen(out);
	w = 0;
	w += ft_prefix(type, out, fl);
	w += ft_out_prec(type, fl, len);
	if (fl.prec > len && is_pnumeric(type))
		len = fl.prec;
	if (type == 's' && fl.prec)
		len = fl.prec;
	else if (type == 's' && fl.prec == 0 && fl.ip == 0)
		fl.prec = len;
	if (fl.padding)
		w += ft_padstr(type, out, fl, len);
	else
		w += ft_out_sprec(type, out, fl);
	return (w);
}
