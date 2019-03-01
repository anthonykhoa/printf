/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:21:25 by anttran           #+#    #+#             */
/*   Updated: 2018/11/30 10:52:23 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = -1;
	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	while (++i < n)
	{
		s2[i] = s1[i];
		if (s1[i] == (unsigned char)c)
			return (s2 + i + 1);
	}
	return (NULL);
}
