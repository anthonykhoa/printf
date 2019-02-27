/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dubz_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:28:51 by anttran           #+#    #+#             */
/*   Updated: 2019/02/20 10:41:59 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dubz_width(char *s, t_attr attr, long double i)
{
	char	*fill;
	char	*tmp;

	tmp = s;
	if ((find_c(attr.flags, '-')) || !find_c(attr.flags, '0'))
	{
		if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || i < 0)
			fill = fill_str(attr.width - ft_strlen(tmp) - 1, ' ');
		else
			fill = fill_str(attr.width - ft_strlen(tmp), ' ');
		s = (find_c(attr.flags, '-')) ? ft_strjoin(tmp, fill) :
		ft_strjoin(fill, tmp);
	}
	else
	{
		if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || i < 0)
			fill = fill_str(attr.width - ft_strlen(s) - 1, '0');
		else
			fill = fill_str(attr.width - ft_strlen(s), '0');
		s = ft_strjoin(fill, tmp);
	}
	free(tmp);
	free(fill);
	return (s);
}
