/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:42:25 by anttran           #+#    #+#             */
/*   Updated: 2019/01/31 12:44:15 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*insert_c(char *s1, char c, unsigned long long n)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = malloc(ft_strlen(s1) + 2);
	while (i < ft_strlen(s1) + 1)
	{
		if (i == n)
		{
			dst[j++] = c;
			dst[j++] = s1[i++];
		}
		else
			dst[j++] = s1[i++];
	}
	dst[j] = '\0';
	return (dst);
}
