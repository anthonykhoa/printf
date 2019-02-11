#include "ft_printf.h"

//static char	*g_x = "0123456789abcdef";
//static char	*g_X = "0123456789ABCDEF";
//static char	*g_o = "01234567";

static char		*oux_attr(char *s, t_attr *attr, unsigned long long l)
{
	if (l < attr->prec)
		s = ft_strjoin(fill_str(attr->prec - l, '0'), s);
	l = ft_strlen(s);
	if (ft_strlen(s) < attr->width)
	{
		if (find_c(attr->flags, '-'))
			s = ft_strjoin(s, fill_str(attr->width - ft_strlen(s), ' '));
		if (!find_c(attr->flags, '-') && !find_c(attr->flags, '0'))
			s = ft_strjoin(fill_str(attr->width - ft_strlen(s), ' '), s);
		if (find_c(attr->flags, '0'))
			s = ft_strjoin(fill_str(attr->width - ft_strlen(s), '0'), s);
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

int			oux(va_list ap, t_attr *attr)
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
