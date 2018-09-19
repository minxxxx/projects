/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:36:04 by khansman          #+#    #+#             */
/*   Updated: 2016/08/07 15:23:37 by jlangman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**Includes
*/
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <curses.h>
# include <term.h>
# include "../libft/includes/libft.h"
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <string.h>

/*
**Forbidden:
**#include <stdio.h>//debug!
**#include <string.h>//debug!
** printf("\n");//debug
*/

/*
**Defines
*/

/*
**		Shorthand:
*/
# define E_EN env->environ
# define E_SI env->env_size
# define E_LI env->line
# define E_ER env->error
# define E_A env->a

# define I_HIS env->input.history
# define I_H_POS env->input.hist_pos
# define I_TMP env->input.temp
# define I_TMP2 env->input.temp2
# define I_L1 env->input.line1
# define I_L2 env->input.line2
# define I_C1 env->input.count1
# define I_C2 env->input.count2
# define I_CUR env->input.cur
# define I_CB env->input.clipboard

# define P_SI par->sing_quote
# define P_DB par->dble_quote
# define P_B par->brac
# define P_AB par->ang_brac
# define P_SB par->sqr_brac
# define P_STR par->str
# define P_K par->k
# define P_SK P_STR[P_K]

/*
**		Error Messages
*/
# define E_MESS01 "\e[31mError: No such file or directory.\n"
# define E_MESS02 "\e[31mError: Command not found.\n"
# define E_MESS03 "\e[31mError: Command failed.\n"
# define E_MESS04 "\e[31mMemory problem.\n"
# define E_MESS05 "\e[31mis_own is not working properly"
# define E_MESS06 "\e[31mError: No mathing variable found\n"
# define E_MESS07 "\e[31mError: env is full.\n"
# define E_MESS08 "\e[31mError: Removing preset variables.\n"
# define E_MESS09 "\e[31mError: Please use the correct format."
# define E_MESS10 "\e[31mError: Variable already exists.\n"
# define E_MESS11 ">>Take a deep breath and try again.<<\n"
# define E_MESS12 E_MESS03 E_MESS11

/*
**		Stings
*/
# define SH_L "\r\e[32m$> \e[0m\e[36m"
# define SH_Q "\r\e[32mdquote> \e[0m\e[36m"
# define CM_EXIT "exit"
# define CM_EXIT_S 5
# define OWN_FUNCS "cd setenv unsetenv env exit help"
# define AL_SYM "$()- "

/*
**		keys
*/
# define K_BKSP 127
# define K_UP "\e[A"
# define K_DOWN "\e[B"
# define K_RIGHT "\e[C"
# define K_LEFT "\e[D"
# define K_F5 "\e[15~"
# define K_F6 "\e[17~"
# define K_F13 "\e[25~"
# define K_F14 "\e[26~"
# define K_F15 "\e[28~"
# define K_F16 "\e[29~"
# define K_F17 "\e[31~"
# define K_F18 "\e[32~"
# define K_F19 "\e[33~"
# define K_DEL "\e[3~"
# define CTRL_C	3
# define CTRL_Z 26
# define K_HOME "\e[H"
# define K_END "\e[F"

/*
**		Other
*/
# define HIST_STORE 0
# define HIST_NEXT 1
# define HIST_PREV 2
# define MAX_HIST 50

# define SCAN_CUR if (scan_dir(s, ".")) return (add_path(".", s))
# define ERROR_6 else ft_putstr(E_MESS06)
# define MAIN_VAR t_env env; char *line; extern char **environ
# define FILE_F FILE	*fopen()
# define E_FILE fopen("db.txt", "r")
# define CL_LINE ft_putchar('\r');while (++l < k) ft_putchar(' ')

/*
**Structures
*/

/*
**		Parenthesis check
*/
typedef struct		s_par
{
	int				sing_quote;
	int				dble_quote;
	int				brac;
	int				ang_brac;
	int				sqr_brac;
	char			*str;
	int				k;
}					t_par;
/*
**		Input manipulation
*/
typedef struct		s_input
{
	char			**history;
	int				hist_pos;
	char			temp;
	char			temp2;
	char			*cur;
	char			*line1;
	char			*line2;
	int				count1;
	int				count2;
	char			*clipboard;
}					t_input;
/*
**		Global Enviroment
*/
typedef struct		s_env
{
	pid_t			pid;
	struct termios	term;
	struct termios	bterm;
	int				nb_col;
	int				nb_row;
	char			*term_name;
	int				enter;
	char			**ret;
	char			**environ;
	int				env_size;
	char			*line;
	int				error;
	char			*a;
	t_input			input;
}					t_env;

/*
**Prototypes
*/

/*
**		checks.c
*/
int					allowed_character(char c);
int					str_valid(t_env *env, char *str);
int					arg_valid(char **sa, int i);
int					check_line(char *line);
void				ft_help(t_env *env, char **sa);
/*
**		command.c
*/
int					do_command(t_env *env, char *com);
void				com_sep(t_env *env, char *s);
void				command(t_env *env, char *s);
/*
**		errors.c
*/
int					error1(int err);
int					error(int err);
/*
**		exit.c
*/
void				free2d(char **arr);
void				exit_prog(t_env *env);
/*
**		get_line.c
*/
char				*re_malloc(char *line, size_t size);
int					get_line(int fd, char **line);
/*
**		own_command.c
*/
int					is_own(char *s);
/*
**		set_env.c
*/
int					env_valid(char *s);
void				set_env(t_env *env, char *s);
/*
**		count.c
*/
int					count(char *s, char c);
/*
**		own_command.c
*/
int					is_own(char *s);
void				own_command(t_env *env, char **sa, char *s);
/*
**		ft_strchr_f.c
*/
int					ft_strchr_f(char *s, char c);
/*
**		get_env.c
*/
char				*add_own(void);
char				**get_env(char **environ);
int					get_envsize(char **env);
/*
**		ft_unset.c
*/
void				ft_removestr(char *big, char *little);
void				ft_unset(char ***sa, char *var);
/*
**		ft_export.c
*/
void				ft_unsetenv(t_env *env, char **sa);
int					is_var(char *s1, char *s2);
void				ft_setenv(t_env *env, char **sa);
void				ft_export(char *sa[], int env_size, char *s);
/*
**		ft_env.c
*/
void				ft_env(char **sa);
void				call_env(t_env env, char *s);
char				*find_var_val(t_env *env, const char *var);
void				update_env(t_env *env, char *var, char *n);
/*
**		find_path.c
*/
int					scan_dir(char *s, char *path);
char				*add_path(char	*path, char	*extension);
char				*find_path(t_env *env, char s[]);
/*
**		echo.c
*/
void				ft_echo(char **sa);
void				ft_print_echo(char **sa);
/*
**		ft_cd.c
*/
int					check(char **sa);
void				cd_home(t_env *env);
void				ft_cd(t_env *env, char **sa);
t_env				*ft_cd_sub(t_env *env, char *sa, int count);
/*
**		trim.c
*/
char				*trim_start(char *str);
void				trim_end(char **str);
void				trim_str(char **str);
int					trim_arr(char ***arr);
void				rm_tabs(char **str);
/*
**		signal.c
*/
void				sig_handler(int signo);
void				sigs(void);
void				restart(void);
/*
**		main.c
*/
void				*back_up_env(void *env);
int					main(void);
/*
**		init_term.c
*/
int					init_term(void);
int					ft_termsize(int y);
/*
**		debug.c
*/
void				put_bin(unsigned char *str);
/*
**		get_input.c
*/
void				get_key(t_env *env);
void				print_line(t_env *env);
int					get_input(t_env *env, int fd, char **line);
/*
**		keys.c
*/
void				key_handler(t_env *env, char *key);
/*
**		com_history.c
*/
int					find_string_pos(char **arr, char *str);
int					com_history(t_env *env, int action);
/*
**		keys_lr.c
*/
char				*ft_add_char_start(char *str, char c);
char				*ft_add_char_end(char *str, char c);
char				*ft_str_inc_dup(char *str);
void				ke_left(t_env *env);
void				ke_right(t_env *env);
/*
**		keys_he.c
*/
void				ke_home(t_env *env);
void				ke_end(t_env *env);
/*
**		keys_w_jump.c
*/
void				ke_jump_left(t_env *env);
void				ke_jump_right(t_env *env);
/*
**		keys_del.c
*/
void				ke_del(t_env *env);
/*
**		keys_cb.c
*/
void				copy_line(t_env *env);
void				copy_l2(t_env *env);
void				paste_l1(t_env *env);
/*
**		check_par.c
*/
int					check_par(t_env *env);
/*
**		cursor.c
*/
void				ft_cursor(void);

/*
**		New Functions Added
*/
int					end_termios(t_env *all);
int					ft_reset_termios(t_env *tmp);
void				ft_print_enter(t_env *all);
int					display(int c);
void				easteregg(t_env *env, char **sa);
int					exit_shell(t_env *tmp, int i);
void				ft_ctrl_c(t_env *env);
void				ft_ctrl_z(t_env *env);

#endif
