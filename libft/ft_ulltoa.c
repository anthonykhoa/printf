/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:00:53 by anttran           #+#    #+#             */
/*   Updated: 2019/01/27 15:38:07 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char *str;
	char *t;
	char *u;

	if (!(str = (char *)malloc(30)))
		return (NULL);
	t = str;
	if (n > 9)
	{
		u = ft_ulltoa(n / 10);
		while (*u)
			*t++ = *u++;
	}
	*t = '0' + n % 10;
	*(t + 1) = '\0';
	return (str);
}
