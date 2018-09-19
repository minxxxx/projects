/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_left_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 13:14:08 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 13:14:09 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*after_while(t_envcp **ev, t_data *en, t_edit **lst, t_hist **hst)
{
	char	*str;

	str = NULL;
	if (ft_sigleton(0) == 3)
	{
		ft_sigleton(-1);
		ft_putchar_fd('\n', STDIN_FILENO);
		str = ft_read_htdoc(ev, en);
	}
	else
	{
		if (*lst)
			ft_jumprint(lst);
		ft_putchar_fd('\n', STDIN_FILENO);
		if ((ft_write_on_file(lst, en->env)) == 0)
		{
			str = ft_create_string(*lst);
		}
		clean_all_static(lst, hst);
		if (!str)
			str = ft_read_htdoc(ev, en);
		return (str);
	}
	return (str);
}

static int	in_while(char **key, t_data **data, t_hist **hst, t_edit **lst)
{
	int		value;

	value = 0;
	(void)hst;
	ft_bzero(*key, 7);
	if ((value = ft_sigleton(0)) > 0)
	{
		ft_signal_2(data, lst);
		return (-1);
	}
	else
	{
		if (read(0, *key, 6) == -1)
			return (-1);
		if ((value = ft_sigleton(0)) == 3)
		{
			ft_signal_2(data, lst);
			return (-1);
		}
	}
	return (0);
}

char		*ft_read_htdoc(t_envcp **env, t_data *data)
{
	char	*str;
	t_hist	*hst;
	t_edit	*lst_e;
	char	*key;

	hst = NULL;
	lst_e = NULL;
	key = (char *)malloc(sizeof(char) * 7);
	ft_bzero(key, 7);
	begin_read(&hst, &lst_e, data);
	while (!ENTER && ft_sigleton(0) != 3)
	{
		if (in_while(&key, &data, &hst, &lst_e) == -1)
		{
			free(key);
			return (NULL);
		}
	}
	if ((str = after_while(env, data, &lst_e, &hst)))
	{
		free(key);
		return (str);
	}
	return (NULL);
}

int			ft_read_db_lft(t_data *data)
{
	int		ret;
	char	line[LINE_LEN];

	data->arrlft.fd = open(".tmp", O_RDONLY, 0644);
	if (data->arrlft.fd == -1)
		return (-1);
	ft_bzero(line, BUF_SIZE);
	while ((ret = read(data->arrlft.fd, &line, BUF_SIZE)) > 0)
	{
		ft_putstr(line);
		ft_bzero(line, BUF_SIZE);
	}
	clean_heredoc(&data);
	return (0);
}

int			ft_db_ar_lft(t_pipe **tmp, t_data *env, int flag)
{
	char	*str;

	if (env->arrlft.fd == 0)
	{
		env->arrlft.fd = open(".tmp", O_CREAT | O_TRUNC | O_WRONLY, 0644);
		env->arrlft.key = ft_strdup((*tmp)->argv[1]);
		if (!env->arrlft.key || env->arrlft.fd == -1)
			return (-1);
		while (ft_strcmp_spe42((str = ft_read_htdoc(env->env_tr, env)),
					env->arrlft.key) != 0)
		{
			write(env->arrlft.fd, str, ft_strlen(str));
			write(env->arrlft.fd, (void *)&("\n"), 1);
		}
		if (env->arrlft.fd > 0)
			clean_heredoc(&env);
		if (flag == 1)
			ft_read_db_lft(env);
	}
	return (0);
}
