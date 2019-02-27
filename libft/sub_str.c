/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:46:35 by anttran           #+#    #+#             */
/*   Updated: 2019/02/20 08:16:22 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sub_str(char *str, char *sub, unsigned long long x)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strdup(str);
	free(str);
	while (sub[++i] && tmp[x])
		tmp[x++] = sub[i];
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}
