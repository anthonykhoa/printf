/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:11:55 by anttran           #+#    #+#             */
/*   Updated: 2019/01/07 09:40:46 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	if (!tab)
		return (0);
	max = tab[0];
	while (++i < len)
		if (max < tab[i])
			max = tab[i];
	return (max);
}
