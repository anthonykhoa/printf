/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:37:05 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 11:14:44 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hash(char *str, t_attr attr, uintmax_t n)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = str;
	if (attr.conv[0] == 'x' && n)
		str = ft_strjoin("0x", tmp + i++);
	else if (attr.conv[0] == 'X' && n)
		str = ft_strjoin("0X", tmp + i++);
	else if (!attr.prec && attr.conv[0] == 'o' && str[0] != '0')
		str = ft_strjoin("0", tmp + i++);
	if (i)
		free(tmp);
	return (str);
}

static char	*width(char *str, t_attr attr, size_t l)
{
	char	*tmp;
	char	*fill;

	if (find_c(attr.flags, '-') || !find_c(attr.flags, '0'))
	{
		tmp = str;
		fill = fill_str(attr.width - ft_strlen(str), ' ');
		if (find_c(attr.flags, '-'))
			str = ft_strjoin(tmp, fill);
		else
			str = ft_strjoin(fill, tmp);
	}
	else
	{
		tmp = str;
		fill = fill_str(attr.width - ft_strlen(str), '0');
		str = ft_strjoin(fill, tmp);
	}
	free(tmp);
	free(fill);
	if (find_c(attr.flags, '#'))
		str = oux_whash(str, attr, l);
	return (str);
}

static char	*print_oux(char *str, uintmax_t n, t_attr attr)
{
	char	*fill;
	char	*tmp;

	if (!n && !attr.prec && attr.sp)
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
		str = hash(str, attr, n);
	return (str);
}

static char	*parse_oux(va_list ap, t_attr attr, uintmax_t n)
{
	char	*str;

	if (!attr.lms[0])
		n = va_arg(ap, unsigned);
	else if (strequ(attr.lms, "hh"))
		n = (unsigned char)va_arg(ap, unsigned);
	else if (strequ(attr.lms, "h"))
		n = (unsigned short)va_arg(ap, unsigned);
	else if (strequ(attr.lms, "l"))
		n = va_arg(ap, unsigned long);
	else if (strequ(attr.lms, "ll"))
		n = va_arg(ap, unsigned long long);
	else if (attr.lms[0] == 'z')
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, uintmax_t);
	if (attr.conv[0] == 'o')
		str = base8(n);
	else if (attr.conv[0] == 'x')
		str = base16x(n);
	else if (attr.conv[0] == 'X')
		str = base16xl(n);
	else
		str = ft_umaxtoa(n);
	return (print_oux(str, n, attr));
}

int			oux(va_list ap, const char *f, int i)
{
	char		*str;
	int			len;
	t_attr		bah;
	uintmax_t	n;

	n = 0;
	bah = set_attr(f, i);
	if (bah.prec && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (find_c(bah.flags, '-') && find_c(bah.flags, '0'))
		remove_c(bah.flags, '0');
	if (!strequ(bah.lms, "l") && (bah.conv[0] == 'U' || bah.conv[0] == 'O'))
	{
		bah.lms[0] = 'l';
		bah.lms[1] = '\0';
	}
	str = parse_oux(ap, bah, n);
	ft_putstr_fd(str, g_fd);
	len = ft_strlen(str);
	free(str);
	return (len);
}
