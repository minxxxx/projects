/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 16:18:50 by ggroener          #+#    #+#             */
/*   Updated: 2016/07/16 16:18:52 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_signal_init(void)
{
	signal(SIGBUS, &ft_signal);
	signal(SIGEMT, &ft_signal);
	signal(SIGFPE, &ft_signal);
	signal(SIGHUP, &ft_signal);
	signal(SIGINT, &ft_signal);
	signal(SIGSYS, &ft_signal);
	signal(SIGABRT, &ft_signal);
	signal(SIGALRM, &ft_signal);
	signal(SIGCONT, &ft_signal);
	signal(SIGKILL, &ft_signal);
	signal(SIGPIPE, SIG_DFL);
	signal(SIGQUIT, &ft_signal);
	signal(SIGSEGV, &ft_signal);
	signal(SIGTERM, &ft_signal);
	signal(SIGTTOU, &ft_signal);
	signal(SIGSTOP, &ft_signal);
	signal(SIGTSTP, &ft_signal);
	signal(SIGUSR1, &ft_signal);
	signal(SIGUSR2, &ft_signal);
	signal(SIGXCPU, &ft_signal);
	signal(SIGXFSZ, &ft_signal);
	signal(SIGWINCH, &ft_signal);
	return (1);
}

static void		ft_signal_set(struct termios **config)
{
	struct termios			new;

	if (*config == NULL)
	{
		ft_signal_init();
		*config = (struct termios *)malloc(sizeof(struct termios));
		tcgetattr(STDIN_FILENO, *config);
	}
	new = **config;
	new.c_iflag |= IGNBRK;
	new.c_lflag |= ISIG;
	new.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | IEXTEN);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
	return ;
}

static int		ft_signal_suspend(struct termios **config, int n)
{
	char					cp[3];

	if (n == SIGTSTP)
	{
		if (*config != NULL)
		{
			ft_clear();
			ft_cmdgoto(0, 0);
			ft_cmdput("ve");
			tcsetattr(0, TCSANOW, *config);
			signal(SIGTSTP, SIG_DFL);
			cp[0] = config[0][0].c_cc[VSUSP];
			cp[1] = '\n';
			cp[2] = '\0';
			ioctl(isatty(1), TIOCSTI, &cp);
			free(*config);
			*config = NULL;
			return (1);
		}
	}
	ft_cmdput("vi");
	ft_signal_set(config);
	return (0);
}

void			ft_signal(int n)
{
	static struct termios	*config;

	if (config == NULL || n == SIGTSTP || n == SIGCONT)
	{
		if (ft_signal_suspend(&config, n))
			return ;
		if (n == SIGCONT)
			ft_putcirc(0, NULL, NULL, 0);
	}
	else if (n == 28 || n == 11)
		ft_putcirc(0, NULL, NULL, 0);
	else
	{
		if (DEBUG)
			ft_printf("-[%d]-", n);
		ft_cmdput("ve");
		ft_cmdput("te");
		tcsetattr(0, TCSANOW, config);
		free(config);
		if (n != -1)
			exit(0);
	}
}
