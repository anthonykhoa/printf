/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 12:47:35 by anttran           #+#    #+#             */
/*   Updated: 2019/02/02 12:48:21 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*rev_str(const char *str)
{
	int		i;
	int		j;
	char	*rev;

	i = 0;
	j = 0;
	rev = malloc(ft_strlen(str) + 1);
	while (str[i])
		i++;
	while (--i > -1)
		rev[j++] = str[i];
	rev[j] = '\0';
	return (rev);
}
