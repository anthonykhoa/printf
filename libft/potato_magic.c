/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   potato_magic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:15:17 by anttran           #+#    #+#             */
/*   Updated: 2019/02/23 21:16:25 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	potato_magic(long double n, char *first, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
	{
		if (n < 0)
			n += (first[i++] - 48) * ft_pow(10, len);
		else
			n -= (first[i++] - 48) * ft_pow(10, len);
	}
	n += (n < 0) ? -1 : 1;
	return (n);
}
