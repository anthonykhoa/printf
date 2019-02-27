/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:04:48 by anttran           #+#    #+#             */
/*   Updated: 2019/02/20 08:25:07 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*push_str(char *str, char *sub)
{
	char				*tmp;
	unsigned long long	i;
	int					j;

	i = 0;
	j = 0;
	tmp = malloc(ft_strlen(str) + 1);
	while (sub[j])
		tmp[i++] = sub[j++];
	j = 0;
	while (i < ft_strlen(str))
		tmp[i++] = str[j++];
	tmp[i] = '\0';
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}
