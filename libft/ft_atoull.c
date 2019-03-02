/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:43:45 by anttran           #+#    #+#             */
/*   Updated: 2019/01/26 18:47:28 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atoull(const char *str)
{
	int					i;
	unsigned long long	number;

	i = 0;
	number = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		number = (number * 10) + str[i++] - '0';
	return (number);
}
