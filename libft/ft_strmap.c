/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 09:55:31 by anttran           #+#    #+#             */
/*   Updated: 2018/12/01 17:01:25 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	size_t	i;

	if (!s || !f || !(r = (char *)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
		r[i] = f(s[i]);
	return (r);
}
