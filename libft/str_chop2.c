/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chop2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:37 by anttran           #+#    #+#             */
/*   Updated: 2019/02/23 14:24:08 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_chop2(char *str, int n)
{
	char	*pork;
	int		i;

	i = -1;
	if (ft_strlen(str) - n <= 0)
		return (NULL);
	pork = malloc(ft_strlen(str) - n + 1);
	pork[ft_strlen(str) - n] = '\0';
	while (++i < (int)ft_strlen(str) - n)
		pork[i] = str[i + n];
	free(str);
	str = ft_strdup(pork);
	free(pork);
	return (str);
}
