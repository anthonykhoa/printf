#include "ft_printf.h"

static char	*sign_options(char *str, t_attr *attr, long long i)
{
	if (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0)
	{
		if (find_c(attr->flags, '-') && i < 0)
			str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
		if (find_c(attr->flags, '-') && find_c(attr->flags, '+') && i > 0)
			str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
		if (find_c(attr->flags, '-') && find_c(attr->flags, ' ') && i > 0)
			str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
		if (find_c(attr->flags, '0') && i < 0)
			str = insert_c(str, '-', hidden_c3(str, g_nums) - 1);
		if (find_c(attr->flags, '0') && find_c(attr->flags, '+') && i > 0)
			str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
		if (find_c(attr->flags, '0') && find_c(attr->flags, ' ') && i > 0)
			str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
		if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
		{
			i < 0 ? (str = insert_c(str, '-', hidden_c3(str, g_nums) - 1)) : 0;
			if (find_c(attr->flags, '+') && i > 0)
				str = insert_c(str, '+', hidden_c3(str, g_nums) - 1);
			if (find_c(attr->flags, ' ') && i > 0)
				str = insert_c(str, ' ', hidden_c3(str, g_nums) - 1);
		}
	}
	return (str);
}

char		*di_attr(char *s, t_attr *attr,
			unsigned long long len, long long i)
{
	if (len < attr->prec)
		s = ft_strjoin(fill_str(attr->prec - len, '0'), s);
	if (ft_strlen(s) < attr->width)
	{
		if (find_c(attr->flags, '-'))
			s = (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0)
			? ft_strjoin(s, fill_str(attr->width - ft_strlen(s) - 1, ' '))
			: ft_strjoin(s, fill_str(attr->width - ft_strlen(s), ' '));
		if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
			s = (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0
			) ? ft_strjoin(fill_str(attr->width - ft_strlen(s) - 1, ' '), s)
			: ft_strjoin(fill_str(attr->width - ft_strlen(s), ' '), s);
		if (find_c(attr->flags, '0'))
			s = (find_c(attr->flags, '+') || find_c(attr->flags, ' ') || i < 0
			) ? ft_strjoin(fill_str(attr->width - ft_strlen(s) - 1, '0'), s)
			: ft_strjoin(fill_str(attr->width - ft_strlen(s), '0'), s);
	}
	s = sign_options(s, attr, i);
	return (s);
}

static char	*print_di(long long i, t_attr *attr)
{
	char				*str;
	unsigned long long	len;

	str = ft_lltoa(i);
	str = (i < 0) ? rem_c(str, '-') : str;
	len = ft_strlen(str);
	str = di_attr(str, attr, len, i);
	return (str);
}	

static char	*parse_di(va_list ap, t_attr *attr, int d)
{
	char		hh;
	short		h;
	long		l;
	long long	ll;

	strequ(attr->lms, "hh") ? (hh = va_arg(ap, int)) : 0;
	strequ(attr->lms, "h") ? (h = va_arg(ap, int)) : 0;
	strequ(attr->lms, "l") ? (l = va_arg(ap, long)) : 0;
	strequ(attr->lms, "ll") ? (ll = va_arg(ap, long long)) : 0;
	!attr->lms[0] ? (d = va_arg(ap, int)) : 0;
	if (strequ(attr->lms, "hh"))
		return (print_di(hh, attr));
	if (strequ(attr->lms, "h"))
		return (print_di(h, attr));
	if (strequ(attr->lms, "l"))
		return (print_di(l, attr));
	if (strequ(attr->lms, "ll"))
		return (print_di(ll, attr));
	if (!attr->lms[0])
		return (print_di(d, attr));
	return (NULL);
}

int			di(va_list ap, t_attr *attr)
{
	char		*str;
	int			d;
	
	d = 0;
	if (attr->conv[0] == 'x')
		ft_putstr(attr->conv);
	if (attr->prec && find_c(attr->flags, '0'))
		remove_c(attr->flags, '0');
	str = parse_di(ap, attr, d);
	ft_putstr(str);
	g_c += ft_strlen(str);
	return (1);
}
