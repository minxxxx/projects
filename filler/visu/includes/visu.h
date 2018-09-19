/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:39:35 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:39:38 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "libft.h"
# include <ncurses.h>

# define COL_GREY 100
# define COL_RED 101
# define COL_LIGHT_RED 102
# define COL_GREEN 103
# define COL_LIGHT_GREEN 104
# define COL_BLUE 105
# define COL_LIGHT_BLUE 106
# define COL_YELLOW 107
# define COL_LIGHT_YELLOW 108
# define COL_WHITE 109

# define IS_RUN 0

typedef struct		s_player
{
	int				id;
	char			*name;
}					t_player;

typedef struct		s_board
{
	int				x;
	int				y;
	int				current_line;
	char			**tab;
}					t_board;

typedef struct		s_piece
{
	int				x;
	int				y;
	int				current_line;
	char			**tab;
}					t_piece;

typedef struct		s_render
{
	WINDOW			*w_left;
	WINDOW			*w_right;
	WINDOW			*win;
	int				run;
}					t_render;

typedef struct		s_app
{
	t_player		p1;
	t_player		p2;
	t_board			board;
	t_piece			piece;
	t_player		current_player;
	int				mode;
	int				line;
	t_list			*list_tmp;
	t_render		render;
	int				is_finish;
	int				p1_score;
	int				p2_score;
	int				start;
	int				speed;
	int				nc;
}					t_app;

void				ft_clear_list(t_app *app);
void				ft_clean_tab(char **tab);
void				ft_print_piece(t_app *app);
void				ft_is_finish(t_app *app);

void				ft_set_winner(t_app *app, char *str);
void				ft_set_player(t_app *app, char *str);
void				ft_set_current_player(t_app *app, char *str);
void				ft_set_board(t_app *app, char *str);
void				ft_set_piece(t_app *app, char *str);

void				ft_nc_key_hook(t_app *app);
int					ft_nc_update(t_app *app);

void				ft_nc_init(t_app *app);
void				ft_init_board_or_piece(t_app *app, char *str);

#endif
