/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:50:54 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 18:21:25 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*base8(uintmax_t n)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	if (!n)
		return (ft_strdup("0"));
	str = malloc(30);
	while (i > -1 && n)
	{
		str[i++] = '0' + (n & 7);
		n = n >> 3;
	}
	str[i] = '\0';
	tmp = str;
	str = rev_str(tmp);
	free(tmp);
	return (str);
}
