/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:55:59 by anttran           #+#    #+#             */
/*   Updated: 2019/01/16 13:01:13 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *s, char c)
{
	int n;

	n = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			n++;
		s++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		start;

	if ((s == 0) || (c == 0) || (!(tab =
		ft_memalloc((sizeof(char *) * (ft_count_words(s, c) + 1))))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		tab[j] = ft_strsub(s, start, i - start);
	}
	return (tab);
}
