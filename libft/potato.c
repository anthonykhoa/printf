/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:25:26 by anttran           #+#    #+#             */
/*   Updated: 2019/02/28 18:43:58 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*confident_potato(char *str, char *first, size_t len, int neg)
{
	while (first[--len] == '9')
		first[len] = '0';
	len++;
	if (first[0] == '0')
	{
		str = malloc(ft_strlen(first) + 2);
		str[0] = '1';
		while (len < ft_strlen(first))
			str[len++ + 1] = '0';
		str[len + 2] = '\0';
		if (neg)
			str = insert_c(str, '-', 0);
		free(first);
		return (str);
	}
	else
	{
		first[len - 1] += 1;
		if (neg)
			first = insert_c(first, '-', 0);
	}
	return (first);
}

static char	*low_carb_potato(long double n, int neg)
{
	char	*str;

	if (n < 0)
		n = -n;
	n += 1;
	n *= ft_pow(10, 7);
	str = round_potato(n);
	if (str[0] == 'P')
	{
		free(str);
		return (neg ? ft_strdup("-1") : ft_strdup("1"));
	}
	str = replace_c(str, '.', 0);
	str = insert_c(str, '0', 0);
	if (neg)
		str = insert_c(str, '-', 0);
	return (str);
}

static char	*mighty_potato(long double n, char *first, size_t len, int neg)
{
	char	*str;
	char	*tmp;

	if (n < 0)
		n = -n;
	str = round_potato(n);
	if (str[0] == 'P')
	{
		free(str);
		return (confident_potato(str, first, len, neg));
	}
	if (len > 1)
	{
		str = str_chop2(str, 1);
		tmp = str;
		str = ft_strjoin(first, tmp);
		free(tmp);
		str = insert_c(str, '.', ft_strlen(first));
	}
	else
		str = insert_c(str, '.', ft_strlen(first));
	if (neg)
		str = insert_c(str, '-', 0);
	free(first);
	return (str);
}

static char	*potato_supreme(long double n, char *first, int neg)
{
	char	*tmp;
	char	c;

	neg = (n < 0) ? 1 : 0;
	if (neg)
		first = str_chop2(first, 1);
	tmp = ft_strdup(first);
	if (neg)
		n += (first[0] - 48) * ft_pow(10, ft_strlen(first));
	else
		n -= (first[0] - 48) * ft_pow(10, ft_strlen(first));
	free(first);
	if (neg)
		n = -n;
	first = ft_lltoa((long long)n);
	n = potato_magic(n, first, ft_strlen(first));
	c = first[ft_strlen(first) - 1];
	free(first);
	tmp = insert_c(tmp, c, ft_strlen(tmp));
	n *= ft_pow(10, 7);
	return (mighty_potato(n, tmp, ft_strlen(tmp), neg));
}

char		*potato(long double n)
{
	char	*first;
	size_t	len;
	int		neg;

	neg = (n < 0) ? 1 : 0;
	if ((long long)n == 0)
		return (low_carb_potato(n, neg));
	first = ft_lltoa((long long)n);
	if (neg)
		first = str_chop2(first, 1);
	len = ft_strlen(first);
	if (len > 1 && len < 19)
		n = potato_magic(n, first, len);
	else if (len == 19)
	{
		free(first);
		first = ft_lltoa((long long)(n / 10));
		return (potato_supreme(n, first, neg));
	}
	n *= ft_pow(10, 7);
	return (!n ? first : mighty_potato(n, first, len, neg));
}
