/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux_whash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:36:50 by anttran           #+#    #+#             */
/*   Updated: 2019/02/20 08:49:33 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_o = "01234567";
static char	*g_x = "0123456789abcdef";
static char	*g_xl = "0123456789ABCDEF";

char	*oux_whash(char *s, t_attr attr, unsigned long long l)
{
	if ((l + 2 <= attr.width) && (attr.conv[0] == 'x' || attr.conv[0] == 'X'))
	{
		if (find_c(attr.flags, '-'))
			s = attr.conv[0] == 'x' ? push_str(s, "0x") : push_str(s, "0X");
		else if (find_c(attr.flags, '0'))
			s = attr.conv[0] == 'x' ? sub_str(s, "0x", 0) : sub_str(s, "0X", 0);
		else if (!find_c(attr.flags, '-') && !find_c(attr.flags, '0'))
		{
			if (attr.conv[0] == 'x')
				s = sub_str(s, "0x", hidden_c3(s, g_x) - 3);
			else
				s = sub_str(s, "0X", hidden_c3(s, g_xl) - 3);
		}
	}
	else if ((l + 1 <= attr.width) && (attr.conv[0] == 'o')
		&& !attr.prec && !find_c(attr.flags, '0'))
	{
		if (find_c(attr.flags, '-'))
			s = push_str(s, "0");
		else
			s = replace_c(s, '0', hidden_c3(s, g_o) - 2);
	}
	return (s);
}
