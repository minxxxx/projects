/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_left_path_tool.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:54:44 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:54:45 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	clean_heredoc(t_data **data)
{
	close((*data)->arrlft.fd);
	if ((*data)->arrlft.key)
		free((*data)->arrlft.key);
	ft_bzero((void *)&((*data)->arrlft), sizeof(t_arrlft));
}

void	clean_all_static(t_edit **lst_e, t_hist **hst)
{
	ft_clean_thist(hst);
	*lst_e = NULL;
	*hst = NULL;
}

void	ft_signal_2(t_data **data, t_edit **lst)
{
	(void)lst;
	clean_heredoc(data);
}

int		ft_strcmp_spe42(const char *s1, const char *s2)
{
	int		result;
	int		i;

	if (!s1 || !s2)
		return (0);
	result = 0;
	i = 0;
	while (*((unsigned char *)s1 + i)
			!= '\0' && *((unsigned char *)s2 + i) != '\0')
	{
		if (*((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
			i++;
		else
			break ;
	}
	return (result = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}

/*
**		goes into ft_create_hst.c
**		goes into ft_filled_lste.c
**		goes into ft_tputs.c
*/

void	begin_read(t_hist **hst, t_edit **lst, t_data *data)
{
	(void)*lst;
	ft_create_hst(hst, data->env);
	ft_filled_lste("", lst, hst);
	ft_putstr_fd("heredoc> ", STDIN_FILENO);
	ft_tputs("sc");
}
