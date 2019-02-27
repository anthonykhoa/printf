/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:35:18 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 09:30:29 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_nums = "0123456789";

static char	*sign_options(char *str, t_attr attr, long long i)
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

static char	*width(char *s, t_attr attr, long long i)
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

static char	*print_di(long long i, t_attr attr)
{
	char	*s;
	char	*tmp;
	char	*fill;

	s = (!i && !attr.prec && attr.sp) ? ft_strdup("") : ft_lltoa(i);
	if (i < 0)
		s = rem_c(s, '-');
	if (ft_strlen(s) < attr.prec)
	{
		fill = fill_str(attr.prec - ft_strlen(s), '0');
		tmp = s;
		s = ft_strjoin(fill, tmp);
		free(tmp);
		free(fill);
	}
	s = (ft_strlen(s) < attr.width) ? width(s, attr, i) : s;
	if ((attr.flags[0] == ' ') && !attr.flags[1])
	{
		tmp = s;
		s = ft_strjoin(" ", tmp);
		free(tmp);
	}
	else if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || i < 0)
		s = sign_options(s, attr, i);
	return (s);
}

static char	*parse_di(va_list ap, t_attr attr, int d)
{
	char		hh;
	short		h;
	long		l;
	long long	ll;

	if (!attr.lms[0])
		return (print_di(d = va_arg(ap, int), attr));
	else if (strequ(attr.lms, "hh"))
		return (print_di(hh = va_arg(ap, int), attr));
	else if (strequ(attr.lms, "h"))
		return (print_di(h = va_arg(ap, int), attr));
	else if (strequ(attr.lms, "l"))
		return (print_di(l = va_arg(ap, long), attr));
	return (print_di(ll = va_arg(ap, long long), attr));
}

int			di(va_list ap, const char *f, int i)
{
	int			d;
	int			len;
	char		*str;
	t_attr		bah;

	d = 0;
	bah = set_attr(f, i);
	if (bah.prec && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, '-') && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, ' ') && find_c(bah.flags, '+'))
		remove_c(bah.flags, ' ');
	if (bah.conv[0] == 'D' && bah.lms[0] != 'l')
	{
		bah.lms[0] = 'l';
		bah.lms[1] = '\0';
	}
	str = parse_di(ap, bah, d);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
