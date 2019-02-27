/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:45:26 by anttran           #+#    #+#             */
/*   Updated: 2018/12/01 17:56:01 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || !(sub = ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[start++];
	return (sub);
}
