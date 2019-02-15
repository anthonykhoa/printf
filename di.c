/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:35:18 by anttran           #+#    #+#             */
/*   Updated: 2019/02/14 18:42:07 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_nums = "0123456789";

static char	*sign_options(char *str, t_attr *attr, long long i)
{
	if (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0)
	{
		if (find_c(attr->flags, '-') && i < 0)
			str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr->flags, '-') && find_c(attr->flags, '+') && i > 0)
			str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr->flags, '-') && find_c(attr->flags, ' ') && i > 0)
			str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr->flags, '0') && i < 0)
			str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr->flags, '0') && find_c(attr->flags, '+') && i > 0)
			str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr->flags, '0') && find_c(attr->flags, ' ') && i > 0)
			str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
		else if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
		{
			if (i < 0)
				str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
			else if (find_c(attr->flags, '+') && i > 0)
				str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
			else if (find_c(attr->flags, ' ') && i > 0)
				str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
		}
	}
	return (str);
}

static char	*print_di(long long i, t_attr *attr)
{
	char				*s;

	s = ft_lltoa(i);
	if (i < 0)
		s = rem_c(s, '-');
	if (ft_strlen(s) < attr->prec)
		s = ft_strjoin(fill_str(attr->prec - ft_strlen(s), '0'), s);
	if (ft_strlen(s) < attr->width)
	{
		if (find_c(attr->flags, '-'))
			s = (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0)
			? ft_strjoin(s, fill_str(attr->width - ft_strlen(s) - 1, ' '))
			: ft_strjoin(s, fill_str(attr->width - ft_strlen(s), ' '));
		else if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
			s = (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0)
			? ft_strjoin(fill_str(attr->width - ft_strlen(s) - 1, ' '), s)
			: ft_strjoin(fill_str(attr->width - ft_strlen(s), ' '), s);
		else if (find_c(attr->flags, '0'))
			s = (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0)
			? ft_strjoin(fill_str(attr->width - ft_strlen(s) - 1, '0'), s)
			: ft_strjoin(fill_str(attr->width - ft_strlen(s), '0'), s);
	}
	s = ((attr->flags[0] == ' ') && !attr->flags[1]) ? ft_strjoin(" ", s) :
		sign_options(s, attr, i);
	return (s);
}

static char	*parse_di(va_list ap, t_attr *attr, int d)
{
	char		hh;
	short		h;
	long		l;
	long long	ll;

	if (!attr->lms[0])
		return (print_di(d = va_arg(ap, int), attr));
	if (strequ(attr->lms, "hh"))
		return (print_di(hh = va_arg(ap, int), attr));
	if (strequ(attr->lms, "h"))
		return (print_di(h = va_arg(ap, int), attr));
	if (strequ(attr->lms, "l"))
		return (print_di(l = va_arg(ap, long), attr));
	return (print_di(ll = va_arg(ap, long long), attr));
}

int			di(va_list ap, t_attr *attr)
{
	int			d;
	int			len;
	char		*str;

	d = 0;
	if (attr->prec && find_c(attr->flags, '0'))
		remove_c(attr->flags, '0');
	str = parse_di(ap, attr, d);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
