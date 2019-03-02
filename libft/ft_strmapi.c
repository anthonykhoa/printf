/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:18:49 by anttran           #+#    #+#             */
/*   Updated: 2018/12/01 16:55:29 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	if (!s || !f || !(s2 = ft_memalloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s))
		s2[i] = f(i, s[i]);
	return (s2);
}
