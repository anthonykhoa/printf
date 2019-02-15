/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dubz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:39:24 by anttran           #+#    #+#             */
/*   Updated: 2019/02/14 19:00:43 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_nums = "0123456789";

static char	*prec(char *str, t_attr *attr)
{
	unsigned long long	l;
	unsigned long long	s;

	if (!find_c(str, '.'))
		str = ft_strjoin(str, ft_strjoin(".", fill_str(attr->prec, '0')));
	s = find_c(str, '.');
	l = ft_strlen(str + s);
	if (l < attr->prec)
		str = ft_strjoin(str, fill_str(attr->prec - l, '0'));
	else
	{
		if (str[s + attr->prec] >= '5' && str[s + attr->prec] <= '9')
			str[s + attr->prec - 1] += 1;
		str = str_chop(str, l - attr->prec);
	}
	return (str);
}

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

static char	*float_attr(char *s, t_attr *attr, long double i)
{
	if (find_c(attr->flags, '#') && !find_c(s, '.'))
		s = ft_strjoin(s, ".");
	if (attr->prec && ((ft_strlen(s + find_c(s, '.')) != attr->prec)
		|| !find_c(s, '.')))
		s = prec(s, attr);
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
	s = (find_c(attr->flags, ' ') && (!attr->flags[1] || (find_c(attr->flags,
	'#') && !attr->flags[2]))) ? ft_strjoin(" ", s) : sign_options(s, attr, i);
	return (s);
}

int			dubz(va_list ap, t_attr *attr)
{
	char		*str;
	double		l;
	long double	xl;
	int			len;

	if (strequ(attr->lms, "L"))
		xl = va_arg(ap, long double);
	else
		l = va_arg(ap, double);
	xl = strequ(attr->lms, "L") ? xl : (long double)l;
	str = ft_ldtoa(xl);
	if (xl < 0)
		str = rem_c(str, '-');
	str = float_attr(str, attr, xl);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
