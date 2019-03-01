/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dubz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:39:24 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 11:15:01 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*dubz_width(char *s, t_attr attr, long double n)
{
	char	*fill;
	char	*tmp;

	tmp = s;
	if ((find_c(attr.flags, '-')) || !find_c(attr.flags, '0'))
	{
		if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || n < 0)
			fill = fill_str(attr.width - ft_strlen(tmp) - 1, ' ');
		else
			fill = fill_str(attr.width - ft_strlen(tmp), ' ');
		s = (find_c(attr.flags, '-')) ? ft_strjoin(tmp, fill) :
		ft_strjoin(fill, tmp);
	}
	else
	{
		if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || n < 0)
			fill = fill_str(attr.width - ft_strlen(s) - 1, '0');
		else
			fill = fill_str(attr.width - ft_strlen(s), '0');
		s = ft_strjoin(fill, tmp);
	}
	free(tmp);
	free(fill);
	return (s);
}

static char	*prec2(char *str, t_attr attr)
{
	unsigned long long	l;
	unsigned long long	s;
	char				*tmp;
	char				*fill;

	s = find_c(str, '.');
	l = ft_strlen(str + s);
	if (l < attr.prec)
	{
		fill = fill_str(attr.prec - l, '0');
		tmp = str;
		str = ft_strjoin(tmp, fill);
		free(tmp);
		free(fill);
	}
	else
	{
		if (str[s + attr.prec] >= '5' && str[s + attr.prec] <= '9')
			str[s + attr.prec - 1] += 1;
		tmp = str;
		str = str_chop(tmp, l - attr.prec);
		free(tmp);
	}
	return (str);
}

static char	*prec(char *str, t_attr attr)
{
	char	*tmp;
	char	*fill;

	if (!find_c(str, '.'))
	{
		fill = fill_str(attr.prec, '0');
		tmp = fill;
		fill = ft_strjoin(".", tmp);
		free(tmp);
		tmp = str;
		str = ft_strjoin(tmp, fill);
		free(tmp);
		free(fill);
	}
	else
		str = prec2(str, attr);
	return (str);
}

static char	*dubz_attr(char *str, t_attr attr, long double n)
{
	char	*tmp;

	if (find_c(attr.flags, '#') && !find_c(str, '.'))
	{
		tmp = str;
		str = ft_strjoin(tmp, ".");
		free(tmp);
	}
	if (attr.prec && ((ft_strlen(str + find_c(str, '.')) != attr.prec)
		|| !find_c(str, '.')))
		str = prec(str, attr);
	if (ft_strlen(str) < attr.width)
		str = dubz_width(str, attr, n);
	if (find_c(attr.flags, ' ') && (!attr.flags[1] || (find_c(attr.flags,
		'#') && !attr.flags[2])))
	{
		tmp = str;
		str = ft_strjoin(" ", tmp);
		free(tmp);
	}
	else if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || n < 0)
		str = dubz_signs(str, attr, n);
	return (str);
}

int			dubz(va_list ap, const char *f, int i)
{
	char		*str;
	double		l;
	long double	xl;
	t_attr		bah;

	bah = set_attr(f, i);
	if (bah.prec && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, '-') && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, ' ') && find_c(bah.flags, '+'))
		remove_c(bah.flags, ' ');
	if (strequ(bah.lms, "L"))
		xl = va_arg(ap, long double);
	else
		l = va_arg(ap, double);
	xl = strequ(bah.lms, "L") ? xl : l;
	str = potato(xl);
	if (xl < 0)
		str = rem_c(str, '-');
	str = dubz_attr(str, bah, xl);
	ft_putstr_fd(str, g_fd);
	xl = ft_strlen(str);
	free(str);
	return (xl);
}
