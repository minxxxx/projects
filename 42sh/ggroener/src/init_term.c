/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlangman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 12:48:33 by jlangman          #+#    #+#             */
/*   Updated: 2016/09/11 11:28:42 by rlutsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**int		ft_exit_shell(t_env *tmp, int i)
**{
**	ft_reset_termios(tmp);
**	exit(i);
**}
**
**int		init_term(t_env *tmp, int i)
**{
**	struct winsize	win;
**
**	if (tgetent(NULL, getenv("TERM")) < 1)
**	{
**		ft_putstr_fd("error: env TERM not set\n, 2");
**		return (0);
**	}
**	if (tcgetattr(0, &(tmp->term)) == -1)
**		return (0);
**	if (i == 1 && tcgetattr(0, &(tmp->bterm)) == -1)
**	   return (0);
**	tmp->term.c_lflag &= ~(ICANON | ECHO);
**	tmp->term.c_cc[VMIN] = 1;
**	tmp->term.c_cc[VTIME] = 0;
**	ioctl(0, TIOCGWINSZ, &win);
**	tmp->nb_col = win.ws_col;
**	tmp->nb_row = win.ws_row;
**	if (tcsetattr(0, 0, &(tmp->term)) == -1)
**		return (0);
**	return (1);
**}
**
**int		ft_reset_termios(t_env *tmp)
**{
**	if (tcsetattr(0, 0, &(tmp->bterm)) == -1)
**		return (0);
**	return (1);
**}
*/

static int	ft_init_deleg(char *str)
{
	ft_putstr_fd("ft_select: ", 2);
	if (str != NULL)
		ft_putendl_fd(str, 2);
	return (1);
}

int			init_term(void)
{
	int				k;
	int				result;
	char			*error;
	char			*type;

	k = 0;
	type = getenv("TERM");
	if (type == NULL && (k = 1))
		ft_init_deleg("Please specify terminal (setenv TERM).");
	if (k)
		result = 0;
	else
		result = tgetent(NULL, type);
	if (result < 0 && (k = 1))
		ft_init_deleg("failed to access the termcap database.");
	if (result == 0 && (k = ft_init_deleg(NULL)))
	{
		error = ft_strdup("undefined terminal type.\n");
		ft_putstr_fd(error, 2);
		free(error);
	}
	return (k);
}

int			ft_termsize(int y)
{
	size_t			ret;
	struct ttysize	twin;
	struct winsize	win;

	ret = 0;
	if (!ioctl(0, TIOCGSIZE, &twin))
		ret = (y) ? twin.ts_lines : twin.ts_cols;
	else if (!ioctl(0, TIOCGWINSZ, &win))
		ret = (y) ? win.ws_row : win.ws_col;
	else
	{
		ft_putstr("ioctl Error: Failed to determine window size.\n.");
		exit(0);
	}
	return ((size_t)ret);
}
