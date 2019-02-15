/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:29:56 by anttran           #+#    #+#             */
/*   Updated: 2019/02/14 15:41:21 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*g_nums = "0123456789";

static int	l(const char *f, t_attr *attr, int i, int conv)
{
	int	s;
	int	e;

	if ((s = hidden_c(f, "hlL", i, conv)))
	{
		e = hidden_c2(f, "hlL", i, conv);
		if (e - s > 1)
			return (0);
		if ((e == s + 1) && ((f[s] != f[e]) || f[e] == 'L'))
			return (0);
		if (!attr->prec && (!attr->width && !attr->flags[0] && f[i - 1] != '%'))
			return (0);
		if (!attr->prec && (attr->width && !match(f, g_nums, s - 1, s)))
			return (0);
		if (!attr->prec && (attr->flags[0] &&
			!attr->width && !match(f, " 0-+#", s - 1, s)))
			return (0);
		attr->lms[0] = f[s];
		attr->lms[1] = (e == s + 1) ? f[s] : '\0';
		if (e == s + 1)
			attr->lms[2] = '\0';
	}
	if (!s)
		attr->lms[0] = '\0';
	return (conv + 1);
}

static int	p(const char *f, t_attr *attr, int i, int conv)
{
	int	s;
	int	p;
	int	e;

	if ((p = hidden_c(f, ".", i, conv)))
	{
		if (!attr->width && (!attr->flags[0] && f[i - 1] != '%'))
			return (0);
		if (!attr->width && attr->flags[0] && !match(f, " 0-+#", i - 1, i))
			return (0);
		s = hidden_c(f, g_nums, p, conv);
		e = hidden_c2(f, g_nums, p, conv);
		if (hidden_c(f, "hlL", i, conv) && !match(f, "hlL", e + 1, e + 2))
			return (0);
		if ((s != e) && !match(f, g_nums, s, e))
			return (0);
		if (!s)
			return (0);
		attr->prec = ft_atoull(f + s);
	}
	if (!p)
		attr->prec = 0;
	return (p ? l(f, attr, ++e, conv) : l(f, attr, i, conv));
}

static int	w(const char *f, t_attr *attr, int i, int conv)
{
	int	e;
	int	c;
	int	prec;

	c = i;
	while ((e = hidden_c(f, g_nums, c, c + 1)))
		c++;
	if (c != i)
	{
		e = c;
		prec = hidden_c(f, ".", i, conv);
		if (prec && (prec != e))
			return (0);
		if (!attr->flags[0] && f[i - 1] != '%')
			return (0);
		attr->width = ft_atoull(f + i);
	}
	if (!e)
		attr->width = 0;
	return (e ? p(f, attr, e, conv) : p(f, attr, i, conv));
}

static int	fl(const char *f, t_attr *attr, int i, int conv)
{
	int	e;
	int	c;
	int	tmp;

	c = i;
	while ((e = hidden_c(f, " 0-+#", c, conv)))
		c++;
	if (c != i)
	{
		e = c;
		c = 0;
		tmp = i - 1;
		while (tmp++ < e)
			if (f[tmp] != '0')
				attr->flags[c++] = f[tmp];
		if (hidden_c(f, "0", i, e + 1))
			attr->flags[c++] = '0';
	}
	if (e == i)
		attr->flags[0] = '\0';
	else
		attr->flags[c] = '\0';
	return (attr->flags[0] ? w(f, attr, e, conv) : w(f, attr, i, conv));
}

int			set_attr(const char *f, t_attr *attr, int i)
{
	int		conv;
	int		prec;

	if (!f[i] || !(conv = hidden_c(f, "cspfdiouxX", i, ft_strlen(f))))
		return (0);
	if ((conv != i + 1) && !match(f, " 0-+#.cspfdiouxXhlL123456789", i, conv))
		return (0);
	if ((conv != i + 1) && (prec = hidden_c(f, ".", i, conv)))
		if (!match(f, g_nums, prec + 1, prec + 2))
			return (0);
	attr->conv[0] = f[conv];
	attr->conv[1] = '\0';
	return (fl(f, attr, i, conv));
}
