/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:22:40 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/09 09:22:43 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# define ENTER (key[0] == 10 && key[1] == 0 && key[2] == 0 && key[3] == 0)
# define FT_FILE "/.42sh_history"
# define SEMICOL 0
# define AND 1
# define OR 2
# define PIPE 3
# define AR_LEFT 4
# define AR_RIGHT 5
# define DB_AR_RIGHT 6
# define DB_AR_LEFT 7
# define COM 8
# include "minishell.h"
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct		s_envcp
{
	char			*buf;
	struct termios	term;
	char			**env;
	struct termios	term_cpy;
}					t_envcp;

/*
**		used in read_left_path_tool.c
*/

typedef struct		s_edit
{
	char			c;
	int				video;
	struct s_edit	*next;
	struct s_edit	*prev;
}					t_edit;

/*
**		used in read_left_path_tool.c
*/

typedef struct		s_hist
{
	int				valid;
	struct s_edit	*ptr;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

typedef struct		s_help
{
	char			*key;
	int				cmp;
}					t_help;

typedef struct		s_arrlft
{
	int				fd;
	char			*key;
}					t_arrlft;

typedef struct		s_data
{
	char			**env;
	char			*home;
	char			*old_pwd;
	char			*pwd;
	char			*path;
	t_envcp			**env_tr;
	t_arrlft		arrlft;
}					t_data;

typedef struct		s_pipe
{
	char			*name;
	int				code;
	int				nbr;
	int				prior;
	int				stat;
	char			**argv;
	struct s_pipe	*next;
	struct s_pipe	*top;
	struct s_pipe	*lft;
	struct s_pipe	*rgt;
}					t_pipe;

/*
** Functions for build lexer and parser.
*/
t_pipe				*ft_make_pipelst(char *str);
int					ft_lexer(char *str, t_data *data);
char				**ft_split(char *str);
int					is_space(char c);
int					is_operands(char c);
char				**ft_get_path(t_data *data);
char				**ft_fill_tab(char *str, int size);
t_pipe				*ft_create_path(t_pipe **lst);

/*
** Functions for read and execute the grammatical path.
*/
int					ft_read_path(t_pipe *tree, t_data *data, int flag);
int					ft_pipecode_path(t_pipe **tmp, t_data *data, int flag);
int					ft_execve(char *cmd, char **argv, t_data *data);
char				*ft_read_htdoc(t_envcp **env, t_data *environ);

/*
** Functions that pipe_code, see on define.
*/
int					ft_ar_rgt(t_pipe **tmp, t_data *data);
int					ft_db_ar_rgt(t_pipe **tmp, t_data *data);
int					ft_ar_lft(t_pipe **tmp, t_data *data);
int					ft_db_ar_lft(t_pipe **tmp, t_data *data, int flag);
void				clean_heredoc(t_data **data);
void				clean_all_static(t_edit **lst_e, t_hist **hst);
void				ft_signal_2(t_data **data, t_edit **lst);
int					ft_strcmp_spe42(const char *s1, const char *s2);
void				begin_read(t_hist **hst, t_edit **lst, t_data *data);
int					ft_read_db_lft(t_data *data);
int					ft_and(t_pipe **tmp, t_data *data);
int					ft_or(t_pipe **tmp, t_data *data);
int					ft_semicol(t_pipe **tmp, t_data *data);
int					ft_pipe(t_pipe **tmp, t_data *env);
int					ft_check_pipes(t_pipe **lst);

/*
** 		Function begin_read us these, see on define.
**		used in read_left_path_tool.c
** 		void	begin_read(t_hist **hst, t_edit **lst, t_data *data);
**		goes into ft_create_hst.c
**		goes into ft_filled_lste.c
**		goes into ft_tputs.c
*/
int					ft_filled_lste(char *key, t_edit **lst, t_hist **hst);
int					ft_create_hst(t_hist **hst, char **env);
int					ft_tputs(char *str);
int					ft_sigleton(int i);
void				ft_jumprint(t_edit **lst);
void				get_winsize(struct winsize *ws);
char				*ft_create_string(t_edit *lst);
int					ft_write_on_file(t_edit **lst, char **env);
int					l_list(t_edit **lst_e);
int					ft_pcur(t_edit **lst);
int					ft_create_hst(t_hist **hst, char **env);
void				ft_clean_thist(t_hist **hst);

#endif
