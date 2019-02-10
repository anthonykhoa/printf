#include "ft_printf.h"

static char	*g_o = "01234567";

static char	*oux_attr(char *s, t_attr *attr, unsigned long long l)
{
	if (l < attr->prec)
		s = ft_strjoin(fill_str(attr->prec - l, '0'), s);
	l = ft_strlen(s);
	if (l < attr->width)
	{
		if (find_c(attr->flags, '-'))
			s = ft_strjoin(s, fill_str(attr->width - ft_strlen(s), ' '));
		if (find_c(attr->flags, '0'))
			s = ft_strjoin(fill_str(attr->width - ft_strlen(s), '0'), s);
		if (find_c(attr->flags, '#') && (l + 2 <= attr->width)
			&& (attr->conv[0] == 'x' || attr->conv[0] == 'X'))
		{
			if (find_c(attr->flags, '-'))
				s = (attr->conv[0] == 'x') ? push_str(s, "0x")
				: push_str(s, "0X");
			if (find_c(attr->flags, '0'))
				s = (attr->conv[0] == 'x') ? sub_str(s, "0x", 0)
				: sub_str(s, "0X", 0);
           // if (!find_c)
            // found problem - it is that i do not have an option for not having - and 0 flags
		}
		if ((find_c(attr->flags, '#') && (l + 1 <= attr->width) && (attr->conv[0] == 'o')
			&& (!attr->prec) && (!find_c(attr->flags, '0'))))
			s = find_c(attr->flags, '-') ? push_str(s, "0") :
			replace_c(s, '0', hidden_c3(s, g_o) - 2);
	}
	if ((l >= attr->width) && find_c(attr->flags, '#'))
	{
		(attr->conv[0] == 'x') ? (s = ft_strjoin("0x", s)) : 0;
		(attr->conv[0] == 'X') ? (s = ft_strjoin("0X", s)) : 0;
        if (!attr->prec)
            (attr->conv[0] == 'o') ? (s = ft_strjoin("0", s)) : 0;
	}
	return (s);
}

static char	*print_oux(unsigned long long i, t_attr *attr)
{
	char				*str;
	unsigned long long	len;

	if (attr->conv[0] == 'o')
		str = base8(i);
	if (attr->conv[0] == 'x')
		str = base16x(i);
	if (attr->conv[0] == 'X')
		str = base16xl(i);
	if (attr->conv[0] == 'u')
		str = ft_ulltoa(i);
	len = ft_strlen(str);
	str = oux_attr(str, attr, len);
	return (str);
}

static char	*parse_oux(va_list ap, t_attr *attr, unsigned u)
{
	unsigned char		hh;
	unsigned short		h;
	unsigned long		l;
	unsigned long long	ll;

	strequ(attr->lms, "hh") ? (hh = va_arg(ap, unsigned)) : 0;
	strequ(attr->lms, "h") ? (h = va_arg(ap, unsigned)) : 0;
	strequ(attr->lms, "l") ? (l = va_arg(ap, unsigned long)) : 0;
	strequ(attr->lms, "ll") ? (ll = va_arg(ap, unsigned long long)) : 0;
	!attr->lms[0] ? (u = va_arg(ap, unsigned)) : 0;
	if (strequ(attr->lms, "hh"))
		return (print_oux(hh, attr));
	if (strequ(attr->lms, "h"))
		return (print_oux(h, attr));
	if (strequ(attr->lms, "l"))
		return (print_oux(l, attr));
	if (strequ(attr->lms, "ll"))
		return (print_oux(ll, attr));
	if (!attr->lms[0])
		return (print_oux(u, attr));
	return (NULL);
}

int		oux(va_list ap, t_attr *attr)
{
	char		*str;
	unsigned	u;

	u = 0;
	if (attr->prec && find_c(attr->flags, '0'))
		remove_c(attr->flags, '0');
	str = parse_oux(ap, attr, u);
	ft_putstr(str);
	g_c += ft_strlen(str);
	return (1);
}
