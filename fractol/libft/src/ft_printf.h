/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuys <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 07:32:45 by jbuys             #+#    #+#             */
/*   Updated: 2016/08/11 12:33:00 by jbuys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../includes/libft.h"

char	*convert(unsigned int num, int base, int hex_upper);

int		ft_printf(char *restrict str, ...);
int		ft_count_ui_num(unsigned int num, int base);

int		printf_format(va_list ap, char *str);
int		printf_format1(va_list ap, char *str);
int		printf_format_mod(va_list ap, char *str);

int		do_compare(char *str);
int		do_flags(va_list ap, char *str);
int		do_hash(va_list ap, char *str);
int		do_plus(va_list ap, char *str);
int		do_minus(va_list ap, char *str);
int		do_space(va_list ap, char *str);

#endif
