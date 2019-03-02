/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:12:44 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 18:23:31 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_umaxtoa(uintmax_t n)
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
		u = ft_umaxtoa(n / 10);
		while (u[i])
			*t++ = u[i++];
		free(u);
	}
	*t = '0' + n % 10;
	*(t + 1) = '\0';
	return (str);
}
