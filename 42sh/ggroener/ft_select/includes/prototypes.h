/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:50:23 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/11 17:57:31 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "ft_select.h"

int				ft_select(t_choice **ch, t_search **s, int *argc, int search);

int				ft_caption(int key, int clear);
void			ft_check(int argc, int key, t_choice **choice, int *pos);
t_choice		*ft_choice(int argc, char **argv);
void			ft_clear(void);
int				ft_cmdgoto(int x, int y);
void			ft_cmdput(char *str);
char			*ft_cmdstr(char *str);
void			ft_colour(char *str, int key, int i, int pos);
int				ft_columns(int argc);
int				ft_decal(int argc, int line);
void			ft_delmenu(int *argc, t_choice **choice, int *pos);
int				ft_getkey(char *str);
int				ft_init(void);
int				ft_maxlen(int argc, t_choice **choice, int y);
int				ft_putchoice(int argc, t_choice **choice, int print);
void			ft_putcirc(int argc, t_choice **choice, int *pos, int key);
void			ft_putmenu(int argc, t_choice **choice, int pos, int key);
int				ft_search(t_choice **o, t_search **t, char *c);
int				ft_putstr_s(char *str, int argc, int col, int pos);
void			ft_signal(int n);
int				ft_sound(int key);
int				ft_termsize(int y);
char			*ft_getch(void);
char			*ft_center(char *str, size_t size);
int				allowed_keys(int key, t_search **s);
int				ft_too_small(int argc);
void			ft_clear_screen(void);

#endif
