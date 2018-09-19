/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:33:14 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/05 15:16:58 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX "0123456789abcdef"

# include <stdarg.h>
# include <string.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
int		ft_intlen(int n);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf_hex(unsigned int n);
int		ft_print_hex(const char *format, int i, va_list ap);
int		ft_printf_hexm(unsigned int n);
int		ft_printf_hexa(unsigned long n);
int		ft_printf_ptr(void *n);
int		ft_printf_nbr_ld(long n);
int		ft_printf_char(char c);
int		ft_printf_nbr(int nb);
int		ft_printf_str(char *str);
int		ft_printf_long(const char *format, int i, va_list ap);
int		ft_toupper(int c);
int		ft_printf_type(const char *format, int i, va_list ap);
int		ft_printf_unbr(unsigned int n);
int		ft_printf_octal(unsigned int n);
void	ft_putnbr_lf(double n);
int		ft_printf_nbr_lf(double n);
void	ft_putnbr_ld(long n);
int		main(void);

#endif
