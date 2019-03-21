/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:30:34 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 11:15:20 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ops(char *str, t_attr attr, size_t len)
{
	char	*tmp;
	char	*fill;

	if ((attr.conv[0] == 's') && (len > attr.prec) && attr.sp)
	{
		tmp = str;
		str = str_chop(tmp, ft_strlen(tmp) - attr.prec);
		free(tmp);
	}
	if (ft_strlen(str) < attr.width)
	{
		tmp = str;
		fill = fill_str(attr.width - ft_strlen(str), ' ');
		if (find_c(attr.flags, '-'))
			str = ft_strjoin(tmp, fill);
		else
			str = ft_strjoin(fill, tmp);
		free(fill);
		free(tmp);
	}
	return (str);
}

static char	*parse_csp(char c, va_list ap)
{
	char	*str;
	char	*tmp;

	if (c == 's')
	{
		if (!(str = va_arg(ap, char*)))
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	else if (c == 'c')
	{
		str = (char*)ft_memalloc(2);
		str[0] = va_arg(ap, int);
	}
	else
	{
		str = base16x((uintmax_t)va_arg(ap, void*));
		tmp = str;
		str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (str);
}

int			csp(va_list ap, const char *f, int i)
{
	char	*str;
	size_t	len;
	t_attr	bah;

	bah = set_attr(f, i);
	str = parse_csp(bah.conv[0], ap);
	str = ops(str, bah, ft_strlen(str));
	ft_putstr_fd(str, g_fd);
	len = ft_strlen(str);
	free(str);
	return (len);
}
