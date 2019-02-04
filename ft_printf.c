#include "ft_printf.h"

int		g_c = 0;
char	*g_flags = " -+#";
char	*g_nums = "0123456789";
char	*g_lms = "hHlL";
char	*g_convs = "cspfdiouxX";
char	*g_prec = ".";
char	*g_all = " 0-+#.cspfdiouxXhHlL123456789";
char	*g_csp = "csp";
char	*g_f = "f";
char	*g_di = "di";
char	*g_ox = "oxX";
char	*g_oux = "ouxX";
char	*g_dioux = "diouxX";
char	*g_flags0 = "0-+#";
char	*g_0 = "0";
char	*g_uf = "-0";
char	*g_cp = "cp";

static int	more_checks(t_attr *attr)
{
	if ((find_c(attr->flags, '-') && find_c(attr->flags, '0')) ||
	   	(find_c(attr->flags, ' ') && find_c(attr->flags, '+')))
		return (0);
	if (attr->conv[0] == 'f' && attr->flags[0])
	   if (attr->flags[0] != 'L' && attr->flags[0] != 'l')
	   	return (0);	   
	if (hidden_c(attr->conv, g_csp, 0, 1))
		if (attr->lms[0] || attr->flags[1] || (hidden_c(attr->conv, g_cp, 0, 1)
			&& attr->prec) || (attr->flags[0] && attr->flags[0] != '-'))
			return (0);
	if (found_u(attr->conv, g_dioux))
	{
		if (find_c(attr->flags, 'L'))
			return (0);
		if (found_u(attr->conv, g_di) && find_c(attr->flags, '#'))
			return (0);
		if ((attr->conv[0] == 'u') && (attr->flags[2] || (attr->flags[0] && 
			!match(attr->flags, g_uf, 0, ft_strlen(attr->flags)))))
			return (0);
		if (find_c(g_ox, attr->conv[0]) && (attr->flags[3] ||
			find_c(attr->flags, '+') || find_c(attr->flags, ' ')))
			return (0);
	}
	return (1);
}

static int	print_arg(va_list ap, const char *f, int i)
{
	t_attr	*attr;

	attr = malloc(sizeof(t_attr));
	if (!set_attr(f, attr, i))
	{
		ft_memdel((void*)(&attr));
		return (0);
	}
	if (!more_checks(attr))
	{
		ft_memdel((void*)(&attr));
		return (0);
	}
	if (attr->conv[0] == 'd' || attr->conv[0] == 'i') 
		return (di(ap, attr));
	if (found_u(attr->conv, g_oux))
		return (oux(ap, attr));
	return (0);
}

int			ft_printf(const char *f, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, f);
	while (f[i])
	{
		if (f[i] == '%')
		{
		   if (!print_arg(ap, f, ++i))
				break ;
		   i = hidden_c(f, g_convs, i, ft_strlen(f) + 1) + 1;
		}
		else
		{
			ft_putchar(f[i++]);
			g_c++;
		}
	}
	va_end(ap);
	return (f[i] ? -1 : g_c);
}
