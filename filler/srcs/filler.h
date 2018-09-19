/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:43:20 by ggroener          #+#    #+#             */
/*   Updated: 2016/06/10 11:43:21 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define LEFT 0
# define RIGHT 1
# define TOP 2
# define BOT 3

typedef struct s_app	t_app;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_pos
{
	t_point			left;
	t_point			right;
	t_point			top;
	t_point			bot;
}					t_pos;

typedef struct		s_piece
{
	int				x;
	int				y;
	char			**tab;
	int				current_line;
}					t_piece;

typedef struct		s_board
{
	int				x;
	int				y;
	char			**tab;
	char			**tmp_tab;
	int				current_line;
}					t_board;

typedef struct		s_dist
{
	int				value;
	unsigned char	id;
	int				block;
}					t_dist;

typedef struct		s_way
{
	void			(*f)(t_app *);
	unsigned char	token;
}					t_way;

struct				s_app
{
	char			id_player;
	t_board			board;
	t_piece			piece;
	t_list			*list_tmp;
	int				mode;
	char			me;
	char			enemy;
	int				id_me;
	int				id_enemy;
	int				id_current_player;
	int				play;
	t_pos			pos[2];
	t_dist			dist[4];
	t_way			way[8];
};

void				ft_print(int y, int x);
void				ft_clear_list(t_app *app);
void				ft_clear_tab(char **tab);
int					ft_is_valid_pos(t_app *app, int y, int x);

void				ft_set_point_right(int player, t_app *app, int y, int x);
void				ft_set_point_left(int player, t_app *app, int y, int x);
void				ft_set_point_top(int player, t_app *app, int y, int x);
void				ft_set_point_bot(int player, t_app *app, int y, int x);

void				ft_set_player(t_app *app, char *str);
void				ft_set_current_player(t_app *app, char *str);
void				ft_set_board(t_app *app, char *str);
void				ft_set_piece(t_app *app, char *str);

void				ft_place_piece_left_bot(t_app *app);
void				ft_place_piece_left_top(t_app *app);
void				ft_place_piece_right_bot(t_app *app);
void				ft_place_piece_right_top(t_app *app);

void				ft_place_piece_top_left(t_app *app);
void				ft_place_piece_top_right(t_app *app);
void				ft_place_piece_bot_left(t_app *app);
void				ft_place_piece_bot_right(t_app *app);

void				ft_init_board_or_piece(t_app *app, char *str);
void				ft_init_way(t_app *app);
void				ft_init_pos(t_app *app);

void				ft_sort_way(t_app *app);
void				ft_calculate_dist(t_app *app);
void				ft_generate_pos(t_app *app);

void				ft_calculate_edge(t_app *app);

#endif
