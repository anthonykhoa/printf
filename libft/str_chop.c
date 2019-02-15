/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:11:42 by anttran           #+#    #+#             */
/*   Updated: 2019/02/12 17:12:37 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_chop(char *str, int n)
{
	char	*pork;
	int		len;

	len = ft_strlen(str) - n;
	if (len <= 0)
		return (NULL);
	pork = malloc(len + 1);
	pork[len] = '\0';
	while (len--)
		pork[len] = str[len];
	return (pork);
}
