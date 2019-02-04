/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:22:06 by anttran           #+#    #+#             */
/*   Updated: 2019/01/27 15:37:52 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *str;
	char *t;
	char *u;

	if (!(str = (char *)malloc(30)))
		return (NULL);
	t = str;
	(n < 0 ? *t++ = '-' : 1);
	if (n > 0)
		n = -n;
	if (n <= -10)
	{
		u = ft_itoa(-(n / 10));
		while (*u)
			*t++ = *u++;
	}
	*t = '0' - n % 10;
	*(t + 1) = '\0';
	return (str);
}
