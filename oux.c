/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:37:05 by anttran           #+#    #+#             */
/*   Updated: 2019/02/14 18:49:07 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_x = "0123456789abcdef";
static char	*g_xl = "0123456789ABCDEF";

static char	*width(char *s, t_attr *attr, unsigned long long l)
{
	if (find_c(attr->flags, '-'))
		s = ft_strjoin(s, fill_str(attr->width - ft_strlen(s), ' '));
	else if (find_c(attr->flags, '0'))
		s = ft_strjoin(fill_str(attr->width - ft_strlen(s), '0'), s);
	else if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
		s = ft_strjoin(fill_str(attr->width - ft_strlen(s), ' '), s);
	if ((find_c(attr->flags, '#') && (l + 1 <= attr->width) &&
		(attr->conv[0] == 'o') && (!attr->prec) && (!find_c(attr->flags, '0'))))
		s = find_c(attr->flags, '-') ? push_str(s, "0") :
		replace_c(s, '0', hidden_c3(s, "01234567") - 2);
	else if (find_c(attr->flags, '#') && (l + 2 <= attr->width)
			&& (attr->conv[0] == 'x' || attr->conv[0] == 'X'))
	{
		if (find_c(attr->flags, '-'))
			s = (attr->conv[0] == 'x') ? push_str(s, "0x") : push_str(s, "0X");
		else if (find_c(attr->flags, '0'))
			s = (attr->conv[0] == 'x') ? sub_str(s, "0x", 0)
			: sub_str(s, "0X", 0);
		else if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
			s = (attr->conv[0] == 'x') ? sub_str(s, "0x", hidden_c3(s, g_x) - 3)
			: sub_str(s, "0X", hidden_c3(s, g_xl) - 3);
	}
	return (s);
}

static char	*print_oux(unsigned long long i, t_attr *attr)
{
	char				*str;

	if (attr->conv[0] == 'o')
		str = base8(i);
	else if (attr->conv[0] == 'x')
		str = base16x(i);
	else if (attr->conv[0] == 'X')
		str = base16xl(i);
	else
		str = ft_ulltoa(i);
	if (ft_strlen(str) < attr->prec)
		str = ft_strjoin(fill_str(attr->prec - ft_strlen(str), '0'), str);
	if (ft_strlen(str) < attr->width)
		str = width(str, attr, ft_strlen(str));
	else if ((ft_strlen(str) >= attr->width) && find_c(attr->flags, '#'))
	{
		if (attr->conv[0] == 'x')
			str = ft_strjoin("0x", str);
		else if (attr->conv[0] == 'X')
			str = ft_strjoin("0X", str);
		else if (!attr->prec)
			str = ft_strjoin("0", str);
	}
	return (str);
}

static char	*parse_oux(va_list ap, t_attr *attr, unsigned u)
{
	unsigned char		hh;
	unsigned short		h;
	unsigned long		l;
	unsigned long long	ll;

	if (!attr->lms[0])
		return (print_oux(u = va_arg(ap, unsigned), attr));
	if (strequ(attr->lms, "hh"))
		return (print_oux(hh = va_arg(ap, unsigned), attr));
	if (strequ(attr->lms, "h"))
		return (print_oux(h = va_arg(ap, unsigned), attr));
	if (strequ(attr->lms, "l"))
		return (print_oux(l = va_arg(ap, unsigned long), attr));
	return (print_oux(ll = va_arg(ap, unsigned long long), attr));
}

int			oux(va_list ap, t_attr *attr)
{
	char		*str;
	unsigned	u;
	int			len;

	u = 0;
	if (attr->prec && find_c(attr->flags, '0'))
		remove_c(attr->flags, '0');
	str = parse_oux(ap, attr, u);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
