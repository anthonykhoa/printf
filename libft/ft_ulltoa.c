/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:00:53 by anttran           #+#    #+#             */
/*   Updated: 2019/02/24 13:05:00 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(unsigned long long n)
{
	char	*str;
	char	*t;
	char	*u;
	int		i;

	if (!(str = (char *)malloc(30)))
		return (NULL);
	t = str;
	if (n > 9)
	{
		i = 0;
		u = ft_ulltoa(n / 10);
		while (u[i])
			*t++ = u[i++];
		free(u);
	}
	*t = '0' + n % 10;
	*(t + 1) = '\0';
	return (str);
}
