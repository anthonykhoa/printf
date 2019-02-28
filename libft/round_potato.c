/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_potato.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:14:17 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 09:42:33 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*self_conscious_potato(char *str, int i)
{
	while (str[i] == '9' && (i - 1))
	{
		if (str[i - 1] != '9')
		{
			str[i] = '0';
			str[i - 1] += 1;
			break ;
		}
		else
			str[i--] = '0';
		if (str[i] == '0')
			str[i] = '1';
	}
	return (str);
}

char		*round_potato(long double n)
{
	char	*str;
	int		i;

	i = 7;
	str = ft_lltoa((long long)n);
	if (str[1] == '9' && str[2] == '9' && str[3] == '9' && str[4] == '9'
			&& str[5] == '9' && str[6] == '9' && str[7] > '4')
	{
		str[0] = 'P';
		while (--i)
			str[i] = '0';
	}
	else if (str[7] > '4' && str[6] == '9')
		str = self_conscious_potato(str, i - 1);
	else if (str[7] > '4' && str[6] != '9')
		str[6] += 1;
	str[7] = '\0';
	return (str);
}
