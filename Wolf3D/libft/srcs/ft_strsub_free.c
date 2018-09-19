/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 13:51:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/24 13:53:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = ft_strsub(s, start, len);
	free((void*)s);
	return (result);
}
