/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:26:55 by anttran           #+#    #+#             */
/*   Updated: 2019/01/30 14:46:22 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_c(char str[], char c)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = -1;
	j = 0;
	while (++i < ft_strlen(str))
		if (str[i] == c)
			j++;
	tmp = ft_memalloc(ft_strlen(str) - j + 1);
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != c)
			tmp[j++] = str[i];
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	free(tmp);
	tmp = NULL;
	str[i] = '\0';
}
