/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:25:26 by anttran           #+#    #+#             */
/*   Updated: 2019/02/11 20:07:12 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ldtoa(long double n)
{
	char		*str;
	long long	l;

	str = malloc(60);
	(n < 0) ? str = "-" : 0;
	(n < 0) ? n = -n : 0;
	str = ft_strjoin(str, ft_lltoa((long long)n));
	n += .00000015;
	n -= (long long)n;
	n *= ft_pow(10, 6);
	l = (long long)n;
	if (!l)
		return (str);
	str = ft_strjoin(str, ".");
	str = ft_strjoin(str, ft_lltoa((long long)n));
	return (str);
}
