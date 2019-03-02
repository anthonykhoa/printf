/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:01:16 by anttran           #+#    #+#             */
/*   Updated: 2018/11/30 17:34:06 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srct;
	char	*dstt;
	size_t	i;

	srct = (char*)src;
	dstt = (char*)dst;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			dstt[i] = srct[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dstt[i] = srct[i];
			i++;
		}
	}
	return (dst);
}
