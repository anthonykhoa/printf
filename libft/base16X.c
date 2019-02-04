/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16X.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:49:35 by anttran           #+#    #+#             */
/*   Updated: 2019/02/02 12:50:28 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*base16X(unsigned long long n)
{
	int		i;
	char	*str;
	char	*x;

	i = 0;
	str = malloc(30);
	x = "0123456789ABCDEF";
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
