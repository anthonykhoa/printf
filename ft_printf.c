/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:33:30 by anttran           #+#    #+#             */
/*   Updated: 2019/02/14 16:31:29 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		g_c;
static int		g_r;

static t_color	g_colors[] =
{
	{"LR", "\e[38;2;225;100;125m"},
	{"LY", "\e[38;2;255;220;65m"},
	{"LG", "\e[38;2;185;225;70m"},
	{"LB", "\e[38;2;80;220;200m"},
	{"LP", "\e[38;2;160;160;255m"},
	{"R", "\e[1;38;2;225;20;20m"},
	{"O", "\e[1;38;2;255;120;10m"},
	{"Y", "\e[1;38;2;255;200;0m"},
	{"G", "\e[1;38;2;80;200;60m"},
	{"B", "\e[1;38;2;50;150;250m"},
	{"P", "\e[1;38;2;150;75;255m"},
	{"BR", "\e[1;48;2;150;0;0m"},
	{"BY", "\e[1;48;2;255;155;0m"},
	{"BG", "\e[1;48;2;0;100;25m"},
	{"BB", "\e[1;48;2;0;65;140m"},
	{"BP", "\e[1;48;2;60;0;125m"}
};

static int	colors(const char *f, int i)
{
	int	s;
	int	e;
	int	c;

	s = i + 1;
	if (!find_c(f + i, '}'))
		return (0);
	e = find_c(f + i, '}') - 2;
	c = -1;
	while (++c < 16)
		if (ft_strnequ(f + s, g_colors[c].key, e - s + 1))
		{
			if (g_r)
				ft_putstr("\033[0m");
			g_r = 1;
			ft_putstr(g_colors[c].value);
			return (hidden_c4(f, "}", i, ft_strlen(f)));
		}
	return (0);
}

static int	csp(va_list ap, t_attr *attr)
{
	char	*str;

	if (attr->conv[0] == 'c')
	{
		str = ft_memalloc(2);
		str[0] = va_arg(ap, int);
	}
	else if (attr->conv[0] == 's')
		str = va_arg(ap, char*);
	else
		str = ft_strjoin("0x", base16x((unsigned long long)va_arg(ap, void*)));
	if ((attr->conv[0] == 's') && (ft_strlen(str) > attr->prec) && attr->prec)
		str = str_chop(str, ft_strlen(str) - attr->prec);
	if (ft_strlen(str) < attr->width)
	{
		if (find_c(attr->flags, '-'))
			str = ft_strjoin(str, fill_str(attr->width - ft_strlen(str), ' '));
		else
			str = ft_strjoin(fill_str(attr->width - ft_strlen(str), ' '), str);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

static int	more_checks(t_attr *attr)
{
	if ((find_c(attr->flags, '-') && find_c(attr->flags, '0')) ||
		(find_c(attr->flags, ' ') && find_c(attr->flags, '+')))
		return (0);
	if (attr->conv[0] == 'f' && attr->flags[0])
		if (attr->flags[0] != 'L' && attr->flags[0] != 'l')
			return (0);
	if (find_c("csp", attr->conv[0]))
		if (attr->lms[0] || attr->flags[1] || (find_c("cp", attr->conv[0])
			&& attr->prec) || (attr->flags[0] && attr->flags[0] != '-'))
			return (0);
	if (find_c("diouxX", attr->conv[0]))
	{
		if (find_c(attr->flags, 'L'))
			return (0);
		if (find_c("di", attr->conv[0]) && find_c(attr->flags, '#'))
			return (0);
		if ((attr->conv[0] == 'u') && (attr->flags[2] || (attr->flags[0] &&
			!match(attr->flags, "-0", 0, ft_strlen(attr->flags)))))
			return (0);
		if (find_c("oxX", attr->conv[0]) && (attr->flags[3] ||
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
		if (!more_checks(attr))
		{
			ft_memdel((void*)(&attr));
			return (0);
		}
	if (attr->conv[0] == 'c' || attr->conv[0] == 's' || attr->conv[0] == 'p')
		g_c += csp(ap, attr);
	else if (attr->conv[0] == 'd' || attr->conv[0] == 'i')
		g_c += di(ap, attr);
	else if (attr->conv[0] == 'f')
		g_c += dubz(ap, attr);
	else
		g_c += oux(ap, attr);
	return (g_c);
}

int			ft_printf(const char *f, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, f);
	while (f[i])
	{
		if ((f[i] == '{') && !(i = colors(f, i)))
			break ;
		if ((f[i] == '%') && (f[i + 1] != '%'))
		{
			if (!print_arg(ap, f, ++i))
				break ;
			i = hidden_c4(f, "cspfdiouxX", i, ft_strlen(f));
		}
		else
		{
			((f[i] == '%') && (f[i + 1] == '%')) ? i++ : 0;
			ft_putchar(f[i++]);
			g_c++;
		}
	}
	g_r ? ft_putstr("\033[0m") : 0;
	va_end(ap);
	return (f[i] ? -1 : g_c);
}
