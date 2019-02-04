/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:00:54 by anttran           #+#    #+#             */
/*   Updated: 2019/01/31 13:48:36 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rem_c(char *str, char c)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = -1;
	j = 0;
	while (++i < ft_strlen(str))
		if (str[i] == c)
			j++;
	tmp = malloc(ft_strlen(str) - j + 1);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != c)
			tmp[j++] = str[i];
	tmp[j] = '\0';
	return (tmp);
}
