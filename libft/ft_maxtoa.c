/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:16:25 by anttran           #+#    #+#             */
/*   Updated: 2019/02/27 18:23:11 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_maxtoa(intmax_t n)
{
	char	*str;
	char	*t;
	char	*u;
	char	*tmp;
	int		i;

	str = malloc(30);
	t = str;
	if (n < 0)
		*t++ = '-';
	if (n > 0)
		n = -n;
	if (n <= -10)
	{
		u = ft_maxtoa(-(n / 10));
		i = 0;
		while (u[i])
			*t++ = u[i++];
		free(u);
	}
	*t = '0' - n % 10;
	*(t + 1) = '\0';
	tmp = ft_strdup(str);
	free(str);
	return (tmp);
}
