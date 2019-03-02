/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:35:18 by anttran           #+#    #+#             */
/*   Updated: 2019/03/01 11:14:00 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_nums = "0123456789";

static char	*sign_options(char *str, t_attr attr, intmax_t n)
{
	if (find_c(attr.flags, '-') && n < 0)
		str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '-') && find_c(attr.flags, '+') && n > 0)
		str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '-') && find_c(attr.flags, ' ') && n > 0)
		str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '0') && n < 0)
		str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '0') && find_c(attr.flags, '+') && n > 0)
		str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
	else if (find_c(attr.flags, '0') && find_c(attr.flags, ' ') && n > 0)
		str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
	else
	{
		if (n < 0)
			str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
		else if (find_c(attr.flags, '+'))
			str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
		else
			str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
	}
	return (str);
}

static char	*width(char *s, t_attr attr, intmax_t n)
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

static char	*di_ops(char *s, intmax_t n, t_attr attr)
{
	char	*tmp;
	char	*fill;

	if (n < 0)
		s = rem_c(s, '-');
	if (ft_strlen(s) < attr.prec)
	{
		fill = fill_str(attr.prec - ft_strlen(s), '0');
		tmp = s;
		s = ft_strjoin(fill, tmp);
		free(tmp);
		free(fill);
	}
	if (ft_strlen(s) < attr.width)
		s = width(s, attr, n);
	if ((attr.flags[0] == ' ') && !attr.flags[1])
	{
		tmp = s;
		s = ft_strjoin(" ", tmp);
		free(tmp);
	}
	else if (find_c(attr.flags, '+') || find_c(attr.flags, ' ') || n < 0)
		s = sign_options(s, attr, n);
	return (s);
}

static char	*parse_di(va_list ap, t_attr attr)
{
	char		*str;
	intmax_t	n;

	if (!attr.lms[0])
		n = va_arg(ap, int);
	else if (strequ(attr.lms, "hh"))
		n = (char)va_arg(ap, int);
	else if (strequ(attr.lms, "h"))
		n = (short)va_arg(ap, int);
	else if (strequ(attr.lms, "l"))
		n = va_arg(ap, long);
	else if (strequ(attr.lms, "ll"))
		n = va_arg(ap, long long);
	else if (attr.lms[0] == 'z')
		n = va_arg(ap, ssize_t);
	else
		n = va_arg(ap, intmax_t);
	str = (!n && !attr.prec && attr.sp) ? ft_strdup("") : ft_maxtoa(n);
	return (di_ops(str, n, attr));
}

int			di(va_list ap, const char *f, int i)
{
	int				len;
	char			*str;
	t_attr			bah;

	bah = set_attr(f, i);
	if (bah.prec && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, '-') && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, ' ') && find_c(bah.flags, '+'))
		remove_c(bah.flags, ' ');
	if (bah.conv[0] == 'D' && !strequ(bah.lms, "l"))
	{
		bah.lms[0] = 'l';
		bah.lms[1] = '\0';
	}
	str = parse_di(ap, bah);
	ft_putstr_fd(str, g_fd);
	len = ft_strlen(str);
	free(str);
	return (len);
}
