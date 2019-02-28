/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden_c3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttran <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:45:12 by anttran           #+#    #+#             */
/*   Updated: 2019/01/31 14:13:18 by anttran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hidden_c3(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (s2[++j])
			if (s1[i] == s2[j])
				return (i + 1);
	}
	return (0);
}