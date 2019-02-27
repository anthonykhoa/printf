/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:35:04 by anttran           #+#    #+#             */
/*   Updated: 2018/11/30 18:49:16 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = -1;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[++i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (!needle[j++ + 1])
				return ((char*)(haystack + i));
		}
	}
	return (NULL);
}
