/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:42:25 by anttran           #+#    #+#             */
/*   Updated: 2019/02/19 15:42:06 by anttran          ###   ########.fr       */
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
	dst = ft_strdup(s1);
	free(s1);
	s1 = malloc(ft_strlen(dst) + 2);
	while (i < ft_strlen(dst) + 1)
	{
		if (i == n)
		{
			s1[j++] = c;
			s1[j++] = dst[i++];
		}
		else
			s1[j++] = dst[i++];
	}
	s1[j] = '\0';
	free(dst);
	return (s1);
}
