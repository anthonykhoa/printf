/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:02:02 by anttran           #+#    #+#             */
/*   Updated: 2019/02/01 11:06:26 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_c(const char *s1, char c, unsigned long long n)
{
	char	*dst;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	dst = malloc(ft_strlen(s1) + 1);
	while (i < ft_strlen(s1))
	{
		if (i == n)
		{
			dst[j++] = c;
			i++;
		}
		else
			dst[j++] = s1[i++];
	}
	dst[j] = '\0';
	return (dst);
}
