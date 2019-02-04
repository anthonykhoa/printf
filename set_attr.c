#include "ft_printf.h"

static int	l(const char *f, t_attr *attr, int i, int conv)
{
	int	s;
	int	e;

	if ((s = hidden_c(f, g_lms, i, conv)))
	{
		e = hidden_c2(f, g_lms, i, conv);
		if (e - s > 1)
			return (0);
		if ((e == s + 1) && ((f[s] != f[e]) || f[s] == 'L' || f[e] == 'L'))
			return (0);
		if (!attr->prec && ((!attr->width && !attr->flags[0] && f[i - 1] != '%')
			|| (attr->width && !match(f, g_nums, s - 1, s)) || (attr->flags[0]
			&& !attr->width && !match(f, g_flags0, s - 1, s))))
			return (0);
		attr->lms[0] = f[s];
		attr->lms[1] = (e == s + 1) ? f[s] : '\0';
		(e == s + 1) ? attr->lms[2] = '\0' : 0;
	}
	i = conv;
	!s ? (attr->lms[0] = '\0') : 0;
	return (i);
}

static int	p(const char *f, t_attr *attr, int i, int conv)
{
	int	s;
	int	p;
	int	e;

	if ((p = hidden_c(f, g_prec, i, conv)))
	{
		if (!attr->width && ((!attr->flags[0] && f[i - 1] != '%') ||
			(attr->flags[0] && !match(f, g_flags0, i - 1, i))))
			return (0);
		s = hidden_c(f, g_nums, p, conv);
		e = hidden_c2(f, g_nums, p, conv);
		if ((hidden_c(f, g_lms, i, conv) && !match(f, g_lms, e + 1, e + 2)) ||
			((s != e) && !match(f, g_nums, s, e)) || !s)
			return (0);
		attr->prec = ft_atoull(f + s);
	}
	!p ? (attr->prec = 0) : 0;
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
		prec = hidden_c(f, g_prec, i, conv);
		if ((prec && (prec != e)) || (!attr->flags[0] && f[i - 1] != '%'))
			return (0);
		attr->width = ft_atoull(f + i);
	}
	!e ? (attr->width = 0) : 0;
	return (e ? p(f, attr, e, conv) : p(f, attr, i, conv));
}

static int	fl(const char *f, t_attr *attr, int i, int conv)
{
	int	e;
	int	c;
	int	tmp;

	c = i;
	while ((e = hidden_c(f, g_flags0, c, conv)))
		c++;
	if (c != i)
	{
		e = c;
		c = 0;
		if (hidden_c(f, g_nums, e, conv) && !match(f, g_nums, e, e + 1))
			return (0);
		tmp = i - 1;
		while (tmp++ < e)
		{
			(hidden_c(f, g_0, i, e + 1) && (f[tmp] != '0')) ?
			(attr->flags[c++] = f[tmp]) : 0;
			!match(f, g_0, i, e + 1) ? (attr->flags[c++] = f[tmp]) : 0;
		}
		hidden_c(f, g_0, i, e + 1) ? attr->flags[c++] = '0' : 0;
	}
	(e == i) ? (attr->flags[0] = '\0') : 0;
	(e != i) ? (attr->flags[c] = '\0') : 0;
	return (attr->flags[0] ? w(f, attr, e, conv) : w(f, attr, i, conv));
}

int			set_attr(const char *f, t_attr *attr, int i)
{
	int		conv;
	int		prec;

	if (!f[i] || !(conv = hidden_c(f, g_convs, i, ft_strlen(f) + 1)))
		return (0);
	if ((conv != i + 1) && !match(f, g_all, i, conv))
		return (0);
	if ((conv != i + 1) && (prec = hidden_c(f, g_prec, i, conv)))
		if (!match(f, g_nums, prec + 1, prec + 2))
			return (0);
	attr->conv[0] = f[conv];
	attr->conv[1] = '\0';
	return (fl(f, attr, i, conv));
}
