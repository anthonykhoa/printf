/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:30:40 by anttran           #+#    #+#             */
/*   Updated: 2018/11/30 21:42:19 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(src);
	len = len < n ? len : n;
	if (!src)
	{
		dst[0] = '\0';
		return (dst);
	}
	ft_memcpy(dst, src, len);
	if (n > len)
		ft_bzero(dst + len, n - len);
	return (dst);
}
