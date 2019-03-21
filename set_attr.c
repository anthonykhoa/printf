/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:29:56 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 19:30:37 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_attr	lm(const char *f, t_attr attr, int i, int conv)
{
	int	s;
	int	e;

	if ((s = hidden_c(f, "hlLzj", i, conv)))
	{
		e = hidden_c2(f, "hlLzj", i, conv);
		attr.lms[0] = f[s];
		attr.lms[1] = (e == s + 1) ? f[s] : '\0';
		if (e == s + 1)
			attr.lms[2] = '\0';
	}
	if (!s)
		attr.lms[0] = '\0';
	return (attr);
}

static t_attr	precision(const char *f, t_attr attr, int i, int conv)
{
	if (f[i] == '.')
	{
		i++;
		if (ft_isdigit(f[i]))
			attr.prec = ft_atoull(f + i);
		else
			attr.prec = 0;
		while (ft_isdigit(f[i]))
			i++;
		attr.sp = 1;
	}
	else
	{
		attr.prec = 0;
		attr.sp = 0;
	}
	return (lm(f, attr, i, conv));
}

static t_attr	width(const char *f, t_attr attr, int i, int conv)
{
	while (find_c("0#+- ", f[i]))
		i++;
	if (ft_isdigit(f[i]))
		attr.width = ft_atoull(f + i);
	else
		attr.width = 0;
	while (ft_isdigit(f[i]))
		i++;
	return (precision(f, attr, i, conv));
}

static t_attr	flags(const char *f, t_attr attr, int i, int conv)
{
	int	e;
	int	c;
	int	tmp;

	c = i;
	e = i;
	while (find_c(" 0-+#", f[c]))
		c++;
	if (c != i)
	{
		e = c;
		c = 0;
		tmp = i - 1;
		while (tmp++ < e)
			if (f[tmp] != '0')
				attr.flags[c++] = f[tmp];
		if (hidden_c(f, "0", i, e + 1))
			attr.flags[c++] = '0';
	}
	if (e == i)
		attr.flags[0] = '\0';
	else
		attr.flags[c] = '\0';
	return (width(f, attr, i, conv));
}

t_attr			set_attr(const char *f, int i)
{
	int		conv;
	t_attr	attr;

	conv = hidden_c(f, "cspfFdDioOuUxX%", i, ft_strlen(f));
	attr.conv[0] = f[conv];
	attr.conv[1] = '\0';
	return (flags(f, attr, i, conv));
}
