/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:46:35 by anttran           #+#    #+#             */
/*   Updated: 2019/02/02 12:50:48 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub_str(const char *str, const char *sub, unsigned long long x)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = malloc(ft_strlen(str) + 1);
	while (str[++i])
		tmp[i] = str[i];
	tmp[i] = '\0';
	i = -1;
	while (sub[++i] && tmp[x])
		tmp[x++] = sub[i];
	return (tmp);
}
