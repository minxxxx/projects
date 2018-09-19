/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:15:14 by ggroener          #+#    #+#             */
/*   Updated: 2016/09/07 14:15:17 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char		*find_malloc_size(char *str)
{
	int		len_str;
	char	*s;
	int		i;

	i = 0;
	len_str = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (is_operands(str[i]))
		{
			if (i != 0 && !is_space(str[i - 1]) && !is_operands(str[i - 1]))
				len_str++;
			if (str[i + 1] != '\0' && !is_space(str[i + 1]) &&
				!is_operands(str[i + 1]))
				len_str++;
		}
		i++;
	}
	s = (char *)malloc((1 + len_str) * sizeof(char));
	s[len_str] = '\0';
	return (s);
}

static char		*check_str(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = 0;
	s = find_malloc_size(str);
	while (str[++i] != '\0')
	{
		if (is_operands(str[i]))
		{
			if (i != 0 && !is_space(str[i - 1])
			&& !is_operands(str[i - 1]))
				s[j++] = ' ';
		}
		s[j] = str[i];
		j++;
		if (is_operands(str[i]))
		{
			if (str[i + 1] != '\0' && !is_space(str[i + 1])
			&& !is_operands(str[i + 1]))
				s[j++] = ' ';
		}
	}
	return (s);
}

static char		*remove_double_space(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i != 0 && is_space(s[i]) && is_space(s[i - 1]))
			j--;
		i++;
		j++;
	}
	i = 0;
	str = (char *)malloc((j + 1) * sizeof(char));
	str[j] = '\0';
	j = 0;
	while (s[i] != '\0')
	{
		while (i != 0 && s[i] != '\0' && is_space(s[i]) && is_space(s[i - 1]))
			i++;
		str[j++] = s[i++];
	}
	return (str);
}

static int		count_malloc(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (is_space(str[i]))
			j++;
		i++;
	}
	return (j + 1);
}

char			**ft_split(char *str)
{
	int		i;
	char	*s;
	char	*s2;
	char	**arr;

	s = check_str(str);
	s2 = remove_double_space(s);
	free(s);
	i = count_malloc(s2);
	arr = ft_fill_tab(s2, i);
	free(s2);
	return (arr);
}
