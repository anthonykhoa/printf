/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 09:33:25 by anttran           #+#    #+#             */
/*   Updated: 2019/01/07 09:40:08 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int *tab, unsigned int len)
{
	unsigned int	i;
	int				min;

	i = 0;
	if (!tab)
		return (0);
	min = tab[0];
	while (++i < len)
		if (min > tab[i])
			min = tab[i];
	return (min);
}
