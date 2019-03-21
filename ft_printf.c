/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:33:30 by anttran           #+#    #+#             */
/*   Updated: 2019/03/01 14:34:59 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		g_c;
static int		g_r;
static int		g_p;

static t_color	g_colors[] =
{
	{"{LR}", "\e[38;2;225;100;125m"},
	{"{LY}", "\e[38;2;255;220;65m"},
	{"{LG}", "\e[38;2;185;225;70m"},
	{"{LB}", "\e[38;2;80;220;200m"},
	{"{LP}", "\e[38;2;160;160;255m"},
	{"{RE}", "\e[1;38;2;225;20;20m"},
	{"{OR}", "\e[1;38;2;255;120;10m"},
	{"{YE}", "\e[1;38;2;255;200;0m"},
	{"{GR}", "\e[1;38;2;80;200;60m"},
	{"{BL}", "\e[1;38;2;50;150;250m"},
	{"{PR}", "\e[1;38;2;150;75;255m"},
	{"{BR}", "\e[1;48;2;150;0;0m"},
	{"{BY}", "\e[1;48;2;255;155;0m"},
	{"{BG}", "\e[1;48;2;0;100;25m"},
	{"{BB}", "\e[1;48;2;0;65;140m"},
	{"{BP}", "\e[1;48;2;60;0;125m"}
};

static int	colors(const char *f, int i)
{
	int	c;

	c = -1;
	while (++c < 16)
		if (ft_strnequ(f + i, g_colors[c].key, 4))
		{
			if (g_r)
				ft_putstr_fd("\033[0m", 1);
			g_r = 1;
			ft_putstr_fd(g_colors[c].value, 1);
			return (i += 4);
		}
	g_c++;
	ft_putchar_fd('{', 1);
	g_p = i + 1;
	if (f[++i] == '{')
		return (colors(f, i));
	return (0);
}

static int	perc(const char *f, int i)
{
	char	*str;
	char	*fill;
	t_attr	bah;
	int		len;

	bah = set_attr(f, i);
	if (bah.width > 1)
	{
		fill = fill_str(bah.width - 1, ' ');
		if (find_c(bah.flags, '-'))
			str = ft_strjoin("%", fill);
		else
			str = ft_strjoin(fill, "%");
		free(fill);
	}
	else
		str = ft_strdup("%");
	ft_putstr_fd(str, g_fd);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int	print_arg(va_list ap, const char *f, int i)
{
	int	x;

	x = i;
	i = hidden_c(f, "cspfFdDioOuUxX%", i, ft_strlen(f));
	if (f[i] == 'c' || f[i] == 's' || f[i] == 'p')
		g_c += csp(ap, f, x);
	else if (f[i] == 'd' || f[i] == 'D' || f[i] == 'i')
		g_c += di(ap, f, x);
	else if (f[i] == 'f' || f[i] == 'F')
		g_c += dubz(ap, f, x);
	else if (f[i] == '%')
		g_c += perc(f, x);
	else
		g_c += oux(ap, f, x);
	return (1);
}

int			ft_fprintf(int fd, const char *f, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	g_fd = fd;
	va_start(ap, f);
	while (f[i])
	{
		if (f[i] == '%' && print_arg(ap, f, ++i))
			i = hidden_c4(f, "cspfFdDioOuUxX%", i, ft_strlen(f));
		else
		{
			ft_putchar_fd(f[i++], fd);
			g_c++;
		}
	}
	va_end(ap);
	return (f[i] ? -1 : g_c);
}

int			ft_printf(const char *f, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	g_fd = 1;
	va_start(ap, f);
	while (f[i])
	{
		if ((f[i] == '{') && !(i = colors(f, i)))
			i = g_p;
		if ((f[i] == '%') && print_arg(ap, f, ++i))
			i = hidden_c4(f, "cspfFdDioOuUxX%", i, ft_strlen(f));
		else
		{
			ft_putchar_fd(f[i++], 1);
			g_c++;
		}
	}
	if (g_r)
		ft_putstr_fd("\033[0m", 1);
	va_end(ap);
	return (f[i] ? -1 : g_c);
}
