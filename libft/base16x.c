/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:48:29 by anttran           #+#    #+#             */
/*   Updated: 2019/02/02 12:49:28 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *base16x(unsigned long long n)
{
	char	*str;
	char	*x;
	int		i;

	i = 0;
	str = malloc(30);
	x = "0123456789abcdef";
	if (!n)
		return ("0");
	while (n)
	{
		str[i++] = x[n & 15];
		n = n >> 4;
	}
	str[i] = '\0';
	str = rev_str(str);
	return (str);
}
