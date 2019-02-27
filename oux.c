/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:37:05 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 15:22:06 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hash(char *str, t_attr attr, unsigned long long l)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	if (!attr.prec && !l && attr.sp && attr.conv[0] != 'o')
		return (str);
	if (attr.conv[0] == 'x' && l)
		str = ft_strjoin("0x", tmp + i++);
	else if (attr.conv[0] == 'X' && l)
		str = ft_strjoin("0X", tmp + i++);
	else if (!attr.prec && attr.conv[0] == 'o' && str[0] != '0')
		str = ft_strjoin("0", tmp + i++);
	if (i)
		free(tmp);
	return (str);
}

static char	*width(char *s, t_attr attr, unsigned long long l)
{
	char	*tmp;
	char	*fill;

	if (find_c(attr.flags, '-') || !find_c(attr.flags, '0'))
	{
		tmp = s;
		fill = fill_str(attr.width - ft_strlen(s), ' ');
		if (find_c(attr.flags, '-'))
			s = ft_strjoin(tmp, fill);
		else
			s = ft_strjoin(fill, tmp);
	}
	else
	{
		tmp = s;
		fill = fill_str(attr.width - ft_strlen(s), '0');
		s = ft_strjoin(fill, tmp);
	}
	free(tmp);
	free(fill);
	if (find_c(attr.flags, '#'))
		s = oux_whash(s, attr, l);
	return (s);
}

static char	*print_oux(unsigned long long i, t_attr attr)
{
	char	*str;
	char	*tmp;
	char	*fill;

	(attr.conv[0] == 'o') ? str = base8(i) : 0;
	(attr.conv[0] == 'x') ? str = base16x(i) : 0;
	(attr.conv[0] == 'X') ? str = base16xl(i) : 0;
	(attr.conv[0] == 'u') ? str = ft_ulltoa(i) : 0;
	if (!i && !attr.prec && attr.sp)
	{
		free(str);
		str = ft_strdup("");
	}
	if (ft_strlen(str) < attr.prec)
	{
		tmp = str;
		fill = fill_str(attr.prec - ft_strlen(tmp), '0');
		str = ft_strjoin(fill, tmp);
		free(tmp);
		free(fill);
	}
	if (ft_strlen(str) < attr.width)
		str = width(str, attr, ft_strlen(str));
	else if ((ft_strlen(str) >= attr.width) && find_c(attr.flags, '#'))
		str = hash(str, attr, i);
	return (str);
}

static char	*parse_oux(va_list ap, t_attr attr, unsigned u)
{
	unsigned char		hh;
	unsigned short		h;
	unsigned long		l;
	unsigned long long	ll;

	if (!attr.lms[0])
		return (print_oux(u = va_arg(ap, unsigned), attr));
	if (strequ(attr.lms, "hh"))
		return (print_oux(hh = va_arg(ap, unsigned), attr));
	if (strequ(attr.lms, "h"))
		return (print_oux(h = va_arg(ap, unsigned), attr));
	if (strequ(attr.lms, "l"))
		return (print_oux(l = va_arg(ap, unsigned long), attr));
	return (print_oux(ll = va_arg(ap, unsigned long long), attr));
}

int			oux(va_list ap, const char *f, int i)
{
	char		*str;
	unsigned	u;
	int			len;
	t_attr		bah;

	u = 0;
	bah = set_attr(f, i);
	if (bah.prec && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, '-') && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (bah.lms[0] != 'l' && (bah.conv[0] == 'U' || bah.conv[0] == 'O'))
	{
		bah.lms[0] = 'l';
		bah.lms[1] = '\0';
	}
	str = parse_oux(ap, bah, u);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
