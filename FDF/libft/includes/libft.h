/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:34:30 by fkhan             #+#    #+#             */
/*   Updated: 2018/07/23 07:32:33 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 10000

size_t	ft_strlen(char *str);
size_t	ft_strlcat(char *s1, char *s2, size_t len);
int		ft_islower(int c);
int		ft_isspace(int c);
int		ft_isupper(int str);
int		ft_isalpha(int str);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);
char	*ft_strrev(char	*str);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, char *s2, unsigned int len);
char	*ft_strcat(char *s1, char *s2);
char	*ft_strncat(char *s1, char *s2, unsigned int len);
char	*ft_strstr(char *s1, char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *s1, const void *s2, size_t len);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t len);
void	*ft_memmove(void *s1, const void *s2, size_t len);
void	*ft_memchr(const void *src, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
void	ft_putchar(char c);
void	ft_putstr(char const *str);
void	ft_putendl(char const *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *str, int fd);
void	ft_putendl_fd(char const *str, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *str);
void	ft_striter(char *str, void (*f)(char *));
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *str, char (*f)(char));
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *str);
char	**ft_strsplit(char const *str, char c);
char	*ft_itoa(int n);
char	*ft_strrejoin(char *s1, char *s2, size_t len);
int		get_next_line(int const fd, char **line);
int		ft_count_words(const char *str, char c);

#endif
