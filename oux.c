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

static char	*width(char *s, t_attr attr, size_t l)
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

static char	*print_oux(char *str, uintmax_t i, t_attr attr)
{
	char	*fill;
	char	*tmp;

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

static char	*parse_oux(va_list ap, t_attr attr, uintmax_t j)
{
	char	*str;

	if (!attr.lms[0])
		j = (unsigned int)va_arg(ap, unsigned);
	else if (strequ(attr.lms, "hh"))
		j = (unsigned char)va_arg(ap, unsigned);
	else if (strequ(attr.lms, "h"))
		j = (unsigned short)va_arg(ap, unsigned);
	else if (strequ(attr.lms, "l"))
		j = (unsigned long)va_arg(ap, unsigned long);
	else if (strequ(attr.lms, "ll"))
		j = (unsigned long long)va_arg(ap, unsigned long long);
	else if (attr.lms[0] == 'z')
		j = (size_t)va_arg(ap, size_t);
	else
		j = va_arg(ap, uintmax_t);
	if (attr.conv[0] == 'o')
		str = base8(j);
	else if (attr.conv[0] == 'x')
		str = base16x(j);
	else if (attr.conv[0] == 'X')
		str = base16xl(j);
	else
		str = ft_umaxtoa(j);
	return (print_oux(str, j, attr));
}

int			oux(va_list ap, const char *f, int i)
{
	char		*str;
	int			len;
	t_attr		bah;
	uintmax_t	j;

	j = 0;
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
	str = parse_oux(ap, bah, j);
	ft_putstr_fd(str, g_fd);
	len = ft_strlen(str);
	free(str);
	return (len);
}
