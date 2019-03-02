/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:14:09 by anttran           #+#    #+#             */
/*   Updated: 2019/01/31 10:05:37 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	found_u(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (s2[++j])
			if (s2[j] == s2[i])
				return (1);
	}
	return (0);
}
