/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 15:25:57 by khansman          #+#    #+#             */
/*   Updated: 2016/07/09 15:26:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*envi_value(char	*envi[], char *s)
{
	int		i;
	int		start;
	size_t	j;

	i = 0;
	while (envi[i])
	{
		j = 0;
		while (s[j] != '=' && s[j] == envi[i][j])
			j++;
		start = (int)j + 1;
		if (s[j++] == '=')
			while (s[j] != ' ' && s[j] != '\n' && s[j] != '\0')
				;
		return (ft_strsub(s, start, j));
		i++;
	}
	return (NULL);
}

void	free3(char *temp1, char *temp2, char *temp3)
{
	if (temp1)
		free(temp1);
	if (temp2)
		free(temp2);
	if (temp3)
		free(temp3);
}

void	free2(char	*temp1, char *temp2)
{
	if (temp1)
		free(temp1);
	if (temp2)
		free(temp2);
}

void	replace_var(char *envi[], char *s)
{
	size_t	i;
	size_t	j;
	char	*temp[3];

	i = 0;
	while (s[i] != '\0')
	{
		j = i;
		while (s[i] != '$')
			i++;
		if (s[i] == '$')
		{
			temp[0] = ft_strsub(s, (int)j, i);
			i++;
			temp[1] = envi_value(envi, s + i);
			temp[2] = ft_strjoin(temp[0], temp[1]);
			free2(temp[0], temp[1]);
			while (s[j] != ' ' && s[j] != '\n' && s[j] != '\0')
				j++;
			temp[0] = s;
			temp[1] = ft_strsub(s, (int)j, j + ft_strlen(s + j));
			s = ft_strjoin(temp[2], temp[1]);
			free3(temp[0], temp[1], temp[2]);
		}
	}
	ft_putstr(s);
}
