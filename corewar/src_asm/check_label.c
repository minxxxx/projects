/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 13:29:42 by daviwel           #+#    #+#             */
/*   Updated: 2016/08/26 11:07:57 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assembler.h>

/*
** This function compares a character to all characters in the LABEL_CHARS macro
*/

int		check_label_char(char c)
{
	int	i;
	int	in;

	i = 0;
	in = 0;
	while (LABEL_CHARS[i])
	{
		if (c == LABEL_CHARS[i])
			in = 1;
		i++;
	}
	if (in == 1)
		return (1);
	else
		return (-1);
}

/*
** This function checks if a label has been constructed in a valid way, and then
** creates a new t_label which is added to a linked list
*/

t_label	*check_label(char *line, int i, int *valid_label, int line_nbr)
{
	int		j;
	char	*name;
	t_label	*label;

	j = i - 1;
	label = NULL;
	if (i == 0 && (*valid_label = -1) == -1)
		return (label);
	if (line[i - 1] == DIRECT_CHAR && !(*valid_label = 0))
		return (label);
	else
	{
		while (j >= 0)
			if (check_label_char(line[j--]) == -1 && (*valid_label = -1) == -1)
				return (label);
		name = (char *)malloc(sizeof(char *) * (i + 1));
		while (j++ < i)
			name[j - 1] = line[j - 1];
		name[j] = '\0';
		label = (t_label *)malloc(sizeof(t_label));
		label->name = name;
		label->line = line_nbr;
	}
	*valid_label = 1;
	return (label);
}
