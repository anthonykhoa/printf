/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:00:54 by anttran           #+#    #+#             */
/*   Updated: 2019/02/19 14:43:32 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rem_c(char *str, char c)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	i = -1;
	j = 0;
	while (++i < ft_strlen(tmp))
		if (tmp[i] == c)
			j++;
	str = malloc(ft_strlen(tmp) - j + 1);
	i = -1;
	j = 0;
	while (tmp[++i])
		if (tmp[i] != c)
			str[j++] = tmp[i];
	str[j] = '\0';
	free(tmp);
	return (str);
}
