/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dubz_signs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:48:54 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 09:53:52 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_nums = "0123465798";

char	*dubz_signs(char *str, t_attr attr, long double i)
{
	if (find_c(attr.flags, '-') && i < 0)
		str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '-') && find_c(attr.flags, '+') && i > 0)
		str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '-') && find_c(attr.flags, ' ') && i > 0)
		str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '0') && i < 0)
		str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '0') && find_c(attr.flags, '+') && i > 0)
		str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '0') && find_c(attr.flags, ' ') && i > 0)
		str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
	else
	{
		if (i < 0)
			str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr.flags, '+'))
			str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
		else
			str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
	}
	return (str);
}
